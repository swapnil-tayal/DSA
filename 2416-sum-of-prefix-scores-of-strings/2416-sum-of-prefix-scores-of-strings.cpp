
struct Node{
    
    Node* links[26];
    bool flag = false;
    int cnt = 0;
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
    Node* getPut(char ch){
        cnt++;
        return links[ch-'a'];
    }
    void setEnd(){
        cnt++;
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
            node = node->getPut(word[i]);
        }
        node->setEnd();
    }
    int f(string &s){
        Node* node = root;
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(node->containsKey(s[i])){
                node = node->get(s[i]);
                ans += node->cnt;
            }else{
                return 0;
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        
        Trie *trie = new Trie();
        for(auto &i: words){
            trie->insert(i);
        }
        vector<int> ans;
        for(auto &i: words){
            ans.push_back(trie->f(i));
        }
        return ans;
    }
};

