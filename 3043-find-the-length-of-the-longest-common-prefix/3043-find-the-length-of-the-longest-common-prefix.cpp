struct Node{
    
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch-'0'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch-'0'] = node;
        return;
    }
    Node* get(char ch){
        return links[ch-'0'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    int f(string s){
        
        Node* node = root;
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(node->containsKey(s[i])){
                cnt++;
                node = node->get(s[i]);
            }else break;
        }
        return cnt;
    }
    
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        Trie *trie = new Trie();
        for(auto &i: arr1){
            string s = to_string(i);
            trie->insert(s);
        }
        
        int ans = 0;
        for(auto &i: arr2){
            string s = to_string(i);
            ans = max(ans, trie->f(s));
        }
        return ans;
    }
};