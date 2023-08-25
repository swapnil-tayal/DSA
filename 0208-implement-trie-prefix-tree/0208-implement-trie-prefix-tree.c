struct Node {
    struct Node* links[26];
    int flag;
};

typedef struct Node Node;

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    for (int i = 0; i < 26; i++) {
        newNode->links[i] = NULL;
    }
    newNode->flag = 0;
    return newNode;
}

int containsKey(Node* node, char ch) {
    return node->links[ch - 'a'] != NULL;
}

void put(Node* node, char ch, Node* childNode) {
    node->links[ch - 'a'] = childNode;
}

Node* get(Node* node, char ch) {
    return node->links[ch - 'a'];
}

void setEnd(Node* node) {
    node->flag = 1;
}

int isEnd(Node* node) {
    return node->flag;
}


typedef struct {
    Node* root;
    
} Trie;



Trie* trieCreate() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    trie->root = createNode();
    return trie;
}

void trieInsert(Trie* trie, char * word) {
    
    Node* node = trie->root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (!containsKey(node, word[i])) {
            Node* newNode = createNode();
            put(node, word[i], newNode);
        }
        node = get(node, word[i]);
    }
    setEnd(node);
}

bool trieSearch(Trie* trie, char * word) {
    
    Node* node = trie->root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (!containsKey(node, word[i])) {
            return 0;
        }
        node = get(node, word[i]);
    }
    return isEnd(node);
}

bool trieStartsWith(Trie* trie, char * prefix) {
    Node* node = trie->root;
    int len = strlen(prefix);
    for (int i = 0; i < len; i++) {
        if (!containsKey(node, prefix[i])) {
            return 0;
        }
        node = get(node, prefix[i]);
    }
    return 1;
}

void trieFree(Trie* trie) {
    if (trie){
        free(trie->root);
        free(trie);
    }
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/