#include "my_pool.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void cleanup_handler(void *plock) {
    pthread_mutex_unlock(plock);
}

void tpool_add(tpool *pool, void *(*func)(void *), void *arg) {
  // TODO
  pthread_mutex_lock(&pool->qlock);
  myCircularQueueEnQueue(pool->arg_queue, arg);
  myFunctionQueueEnQueue(pool->func_queue, func);
  pthread_mutex_unlock(&pool->qlock);
  pthread_cond_signal(&pool->qready);
  return;
}
void* threadpool(void* arg){
  tpool* pool = (tpool*) arg;
  while(1){
    pthread_cleanup_push(cleanup_handler, &pool->qlock);
    pthread_mutex_lock(&pool->qlock);
    while(myCircularQueueIsEmpty(pool->arg_queue)){
      pthread_cond_wait(&pool->qready, &pool->qlock);
    }
    int tmp_index = myCircularQueueDeQueue(pool->arg_queue);
    myFunctionQueueDeQueue(pool->func_queue);
    pthread_mutex_unlock(&pool->qlock);
    (*pool->func_queue->arr[tmp_index])(pool->arg_queue->arr[tmp_index]);
    pthread_cleanup_pop(0);
  }
}
void tpool_wait(tpool *pool) {
  // TODO
    for(int i = 0; i < pool->thread_size; i++){
        int s = pthread_cancel(pool->tcb[i]);
    }
    for(int i = 0; i < pool->thread_size; i++){
        pthread_join(pool->tcb[i], NULL);
    }
}

void tpool_destroy(tpool *pool) {
  // TODO
  pthread_mutex_destroy(&pool->qlock);
  pthread_cond_destroy(&pool->qready);
  free(pool);
}

tpool *tpool_init(int n_threads) {
  // TODO
  
  tpool *pool = (tpool*) malloc(sizeof(struct tpool));
  pthread_cond_init(&pool->qready, NULL);
  pthread_mutex_init(&pool->qlock, NULL);
  pool->tcb = (pthread_t*)malloc(sizeof(pthread_t) * n_threads);
  pool->arg_queue = myCircularQueueCreate();
  pool->func_queue = myFunctionQueueCreate();
  pool->thread_size = n_threads;

  for(int i = 0; i < n_threads; i++){
    pthread_t tmp;
    pthread_create(&tmp, NULL, (void *)&threadpool, (void*)pool);
    pool->tcb[i] = tmp;
  }

  return pool;
}