#include <pthread.h>
#include "functionq.h"
#include "cqueue.h"

#ifndef __MY_THREAD_POOL_H
#define __MY_THREAD_POOL_H

typedef struct tpool {
  // TODO: define your structure
  int thread_size;
  pthread_t *tcb;
  MyCircularQueue* arg_queue;
  MyFunctionQueue* func_queue;
  pthread_cond_t qready;
  pthread_mutex_t qlock;
} tpool;

tpool *tpool_init(int n_threads);
void tpool_add(tpool *, void *(*func)(void *), void *);
void tpool_wait(tpool *);
void tpool_destroy(tpool *);

#endif