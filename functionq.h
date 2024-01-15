#ifndef __MY_FUNCTION_QUEUE_H
#define __MY_FUNCTION_QUEUE_H
#include<stdlib.h>
typedef struct {
    void (*arr[8388608])(void *);
    int arr_length;
    int arr_size;
    int first;
    int curr;
} MyFunctionQueue;

MyFunctionQueue* myFunctionQueueCreate();
int myFunctionQueueIsEmpty(MyFunctionQueue* obj);
int myFunctionQueueIsFull(MyFunctionQueue* obj);
int myFunctionQueueEnQueue(MyFunctionQueue* obj, void *value);
int myFunctionQueueDeQueue(MyFunctionQueue* obj);
void* myFunctionQueueFront(MyFunctionQueue* obj);
void myFunctionQueueFree(MyFunctionQueue* obj);

#endif