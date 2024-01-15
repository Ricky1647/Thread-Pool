#include "cqueue.h"
#include <stdio.h>

MyCircularQueue* myCircularQueueCreate() {
    MyCircularQueue* res = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    res->arr_length = 8388608;
    res->arr_size = 0;
    res->first = 0;
    res->curr = -1;
    return res;
}

int myCircularQueueIsEmpty(MyCircularQueue* obj) {
    
    return obj->arr_size == 0;
}

int myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->arr_size == obj->arr_length;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}

int myCircularQueueEnQueue(MyCircularQueue* obj, void* arg) {
    
    if(myCircularQueueIsFull(obj)){
        return 0;
    }
    // printf("idskgdspgkdsgpodskgpodsg %d\n", obj->arr_size);
    obj->arr_size ++;
    // printf("idskgdspgkdsgpodskgpodsg %d\n", obj->arr_size);

    obj->curr = (obj->curr + 1) % obj->arr_length;
    obj->arr[obj->curr] = arg;        
    return 1;   
}

int myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return 0;
    int first = obj->first;
    obj->arr_size --;
    obj->first = (obj->first + 1) % obj->arr_length;
    return first;
}

// void* myCircularQueueFront(MyCircularQueue* obj) {
//     // if(myCircularQueueIsEmpty(obj))
//     //     return -1;
//     // else{
//     int first = obj->first;
//     myCircularQueueDeQueue(obj);
//     return obj->arr[first];
    
// }



/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/