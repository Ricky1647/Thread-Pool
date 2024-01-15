#ifndef __MY_QUEUE_H
#define __MY_QUEUE_H
#include<stdlib.h>
typedef struct {
    void* arr[8388608];
    int arr_length;
    int arr_size;
    int first;
    int curr;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate();
int myCircularQueueIsEmpty(MyCircularQueue* obj);
int myCircularQueueIsFull(MyCircularQueue* obj);
int myCircularQueueEnQueue(MyCircularQueue* obj, void *value);
int myCircularQueueDeQueue(MyCircularQueue* obj);
void* myCircularQueueFront(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj);

#endif