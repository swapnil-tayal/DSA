class Node{
    Node* links[26];
    bool flag;
    public:
    bool containsKey(char ch){
        if(links[ch-'0'] != NULL) return true;
        else return false;
    }
    void put(char ch, Node* node){
        links[ch-'0'] = node;
    }
    Node* get(char ch){
        return links[ch-'0'];
    }
    bool isEnd(){
        return flag;
    }
    void setEnd(){
        this->flag = true;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        int n = word.size();
        for(int i=0; i<n; i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word) {
        Node* node = root;
        int n = word.size();
        for(int i=0; i<n; i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            
            }else  return false;
            
        }
        return node->isEnd();
    }
    void f(Node* node, string &str, vector<int> &ans){
        for(int i=0; i<10; i++){
            char ch = char(('0')+i);
            if(node->containsKey(ch)){
                str += ch;
                ans.push_back(stoi(str));
                f(node->get(ch), str, ans);
                str.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        Trie* trie = new Trie();
        for(int i=1; i<=n; i++){
            trie->insert(to_string(i));
        }
        vector<int> ans;
        string str = "";
        trie->f(trie->root, str, ans);
        return ans;
    }
};