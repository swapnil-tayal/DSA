struct Node{
    
    Node* links[26];
    bool flag = false;
    int cost = 1e9;
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
        return;
    }
    void setCost(int cost){
        this->cost = min(this->cost, cost);
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

map<string, int> mp;
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word, int cost) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setCost(cost);
        node->setEnd();
    }
    // TRIE + DP
    int checkIfMadeArrayWords(int ind, string &word, vector<int> &dp){
        
        if(ind == word.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        Node* node = root;
        int ans = 1e9;
        for(int i=ind; i<word.size(); i++){
            if(node->containsKey(word[i])){
                
                node = node->get(word[i]);
                if(node->isEnd()){
                    int cost = node->cost + checkIfMadeArrayWords(i+1, word, dp);    
                    ans = min(cost, ans);
                }
            }else return dp[ind] = ans;
        }
        return dp[ind] = ans;
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        
        mp.clear();
        Trie *trie = new Trie();
        for(int i=0; i<words.size(); i++){
            trie->insert(words[i], costs[i]);
        }
        // for(int i=0; i<words.size(); i++){
        //     if(mp.find(words[i]) == mp.end()) mp[words[i]] = costs[i];
        //     else mp[words[i]] = min(mp[words[i]], costs[i]);
        // }
        vector<int> dp(target.size(), -1);
        int ans = trie->checkIfMadeArrayWords(0, target, dp);
        if(ans == 1e9) return -1;
        else return ans;
    }
};