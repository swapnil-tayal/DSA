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
    bool checkIfMadeArrayWords(int ind, string &word, vector<int> &dp){
        
        if(ind == word.size()) return true;
        if(dp[ind] != -1) return dp[ind];
        
        Node* node = root;
        for(int i=ind; i<word.size(); i++){
            
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                if(node->isEnd()){
                    if(checkIfMadeArrayWords(i+1, word, dp)) return dp[ind] = true;
                }
            }else return dp[ind] = false;
        }
        return dp[ind] = false;
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        Trie *trie = new Trie();
        for(auto &i: wordDict) trie->insert(i);
        vector<int> dp(s.size(), -1);
        return trie->checkIfMadeArrayWords(0, s, dp);
    }
};