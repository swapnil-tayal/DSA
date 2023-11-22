class Node{
    public:
    int key, val, cnt;
    Node* prev; 
    Node* next;
    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->cnt = 1;
    }
};

class List {
    public:
    int size; 
    Node *head; 
    Node *tail; 
    List() {
        head = new Node(0, 0); 
        tail = new Node(0,0); 
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    
    void addFront(Node *node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++; 
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    }
};

class LFUCache {
    map<int, Node*> mpKey;
    map<int, List*> mpFreq;
    int minFreq;
    int currSize;
    int maxCap;
    
    void updateFreq(Node* node){
        
        mpKey.erase(node->key);
        mpFreq[node->cnt]->removeNode(node);
        if(node->cnt == minFreq and mpFreq[node->cnt]->size == 0){
            minFreq++;
        }
        List* newList = new List();
        if(mpFreq.find(node->cnt + 1) != mpFreq.end()){
            newList = mpFreq[node->cnt + 1];
        }
        node->cnt++;
        newList->addFront(node);
        mpFreq[node->cnt] = newList;
        mpKey[node->key] = node;
    }

public:
    LFUCache(int capacity){
        maxCap = capacity;
        minFreq = 0;
        currSize = 0;
    }                     
    
    int get(int key){
        
        if(mpKey.find(key) != mpKey.end()){
            
            Node* node = mpKey[key];
            int val = node->val;
            updateFreq(node);
            return val;
            
        }return -1;
    }
    
    void put(int key, int value) {
        
        if(!maxCap) return;
        
        if(mpKey.find(key) != mpKey.end()){
            Node* node = mpKey[key];
            node->val = value;
            updateFreq(node);
        
        }else{
                
            if(currSize == maxCap){
                
                List *newList = mpFreq[minFreq];
                mpKey.erase(newList->tail->prev->key);
                mpFreq[minFreq]->removeNode(newList->tail->prev);
                currSize--;
                
            }currSize++;
            minFreq = 1;
            List* newList = new List();
            if(mpFreq.find(minFreq) != mpFreq.end()){
                newList = mpFreq[minFreq];
            }
            
            Node* node = new Node(key, value);
            newList->addFront(node);
            mpKey[key] = node;
            mpFreq[minFreq] = newList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */