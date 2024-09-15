struct Node{
    
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
        return;
    }
    Node* get(char ch){
        return links[ch-'a'];
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
    
    // TRIE + DP
    int f(int ind, string &word, vector<int> &dp){
        
        if(ind == word.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        Node* node = root;
        int ans = 1e9;
        for(int i=ind; i<word.size(); i++){
            
            if(node->containsKey(word[i])){
                
                node = node->get(word[i]);
                ans = min(ans, 1 + f(i+1, word, dp));

            }else break;
        }
        return dp[ind] = ans;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        
        Trie* trie = new Trie();
        for(auto i: words){
            trie->insert(i);
        }
        vector<int> dp(target.size(), -1);
        int ans = trie->f(0, target, dp);
        return ans == 1e9 ? -1 : ans;
    }
};