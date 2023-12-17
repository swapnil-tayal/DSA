
typedef struct {
    
    int start;
    int end;
    int ele;
    int arr[];
    
} MyQueue;


MyQueue* myQueueCreate() {
    
    MyQueue *myq = malloc(sizeof(MyQueue) + 2000*sizeof(int));
    // myq->arr = (int*)malloc(2000*sizeof(int)); 
    myq->start = -1;
    myq->end = -1;
    myq->ele = 0;
    return myq;
}

void myQueuePush(MyQueue* obj, int x) {
    
    obj->arr[++(obj->end)] = x;
    (obj->ele)++;
    if(obj->start == -1) obj->start = 0;
}

int myQueuePop(MyQueue* obj) {
    
    (obj->ele)--;
    return obj->arr[(obj->start)++];
}

int myQueuePeek(MyQueue* obj) {
    return obj->arr[obj->start];
}

bool myQueueEmpty(MyQueue* obj) {
    
    if(obj->ele == 0) return true;
    else return false;
}

void myQueueFree(MyQueue* obj) {
    
    obj->start = -1;
    obj->end = -1;
    obj->ele = 0;
}