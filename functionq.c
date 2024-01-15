#include "functionq.h"
#include <stdio.h>

MyFunctionQueue* myFunctionQueueCreate() {
    MyFunctionQueue* res = (MyFunctionQueue*) malloc(sizeof(MyFunctionQueue));
    res->arr_length = 8388608;
    res->arr_size = 0;
    res->first = 0;
    res->curr = -1;
    return res;
}

int myFunctionQueueIsEmpty(MyFunctionQueue* obj) {
    // printf("idskgdspgkdsgpodskgpodsg %d\n",obj->arr_size == 0);
    return obj->arr_size == 0;
}

int myFunctionQueueIsFull(MyFunctionQueue* obj) {
    return obj->arr_size == obj->arr_length;
}

void myFunctionQueueFree(MyFunctionQueue* obj) {
    free(obj);
}

int myFunctionQueueEnQueue(MyFunctionQueue* obj, void* arg) {
    if(myFunctionQueueIsFull(obj)){
        return 0;
    }
    obj->arr_size ++;
    // printf("EEkdfjpiovkdopkopkpkfekfopwekfepf %d\n", obj->arr_size);
    obj->curr = (obj->curr + 1) % obj->arr_length;
    obj->arr[obj->curr] = arg;        
    return 1;   
}

int myFunctionQueueDeQueue(MyFunctionQueue* obj) {
    if(myFunctionQueueIsEmpty(obj))
        return 0;
    int first = obj->first;
    obj->arr_size --;
    obj->first = (obj->first + 1) % obj->arr_length;
    return first;
}

// void* myFunctionQueueFront(MyFunctionQueue* obj) {
//     // if(myFunctionQueueIsEmpty(obj))
//     //     return -1;
//     // else{
//     int first = obj->first;
//     myFunctionQueueDeQueue(obj);
//     return obj->arr[first];
    
// }



/**
 * Your MyFunctionQueue struct will be instantiated and called as such:
 * MyFunctionQueue* obj = myFunctionQueueCreate(k);
 * bool param_1 = myFunctionQueueEnQueue(obj, value);
 
 * bool param_2 = myFunctionQueueDeQueue(obj);
 
 * int param_3 = myFunctionQueueFront(obj);
 
 * int param_4 = myFunctionQueueRear(obj);
 
 * bool param_5 = myFunctionQueueIsEmpty(obj);
 
 * bool param_6 = myFunctionQueueIsFull(obj);
 
 * myFunctionQueueFree(obj);
*/