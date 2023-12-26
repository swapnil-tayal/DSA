class Node{
    Node* link[2];
    public:
    void put(int x, Node* node){
        link[x] = node;
    }
    Node* get(int x){
        return link[x];
    }
    bool containsKey(int x){
        if(link[x] == NULL) return false;
        return true;
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int n){
        
        Node* node = root;
        bitset<32> it(n);
        for(int i=31; i>=0; i--){
            if(!node->containsKey(it[i])){
                node->put(it[i], new Node());
            }
            node = node->get(it[i]);
        }
    }
    int getMax(int x){
        
        Node* node = root;
        bitset<32> it(x);
        int ans = 0; 
        
        for(int i=31; i>=0; i--){
            int y = 1 - it[i];
            if(node->containsKey(y)){
                ans = ans | (1 << i);
                node = node->get(y);
            
            }else node = node->get(it[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        Trie *trie = new Trie();
        for(auto &i: nums){
            trie->insert(i);
        }
        int ans = 0;
        for(auto &i: nums){
            ans = max(ans, trie->getMax(i));
        }
        return ans;
    }
};