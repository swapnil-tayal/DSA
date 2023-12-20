


typedef struct {
    int str;
    int end;
    int ele;
    int arr[];
} MyQueue;


MyQueue* myQueueCreate() {
    
    MyQueue *q = malloc(sizeof(MyQueue) * 2000*(sizeof(int)));
    q->str = -1;
    q->end = -1;
    q->ele = 0;
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    
    obj->arr[++(obj->end)] = x;
    obj->ele++;
    if(obj->str == -1) obj->str = 0;
}

int myQueuePop(MyQueue* obj) {
    obj->ele--;
    int x = obj->arr[(obj->str)++];
    return x;
}

int myQueuePeek(MyQueue* obj) {
    return obj->arr[obj->str];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->ele == 0;
}

void myQueueFree(MyQueue* obj) {
    obj->ele = 0;
    obj->str = -1;
    obj->end = -1;
}