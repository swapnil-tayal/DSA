class node {
    public:
    int key;
    int val;
    node* next;
    node* prev;
    node(int _key, int _val) {
        key = _key;
        val = _val; 
    }
};
    

class LRUCache {
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    unordered_map<int, node*> mp;
    int cap;
    
    void deleteNode(node* delNode){
        node* delPrev = delNode->prev;
        node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    void addNode(node* newNode){
        node* prevHeadNext = head->next;
        newNode->next = prevHeadNext;
        newNode->prev = head;
        head->next = newNode;
        prevHeadNext->prev = newNode;
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end()) return -1;
        else{
            
            node* x = mp[key];
            int k = x->val;
            mp.erase(key);            
            deleteNode(x);
            addNode(x);
            mp[key] = head->next;
            return k;
        }
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){
            node* existNode = mp[key];
            mp.erase(key);
            deleteNode(existNode);
        }
        if(mp.size() == cap){      
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */