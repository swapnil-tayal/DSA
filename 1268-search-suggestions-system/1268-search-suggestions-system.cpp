struct Node{
    
    Node* links[26];
    bool flag = false;

    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    // put char in current node's link and assign new Node reference to it
    void put(char ch, Node* node){
        links[ch-'a'] = node;
        return;
    }
    // return next node reference
    Node* get(char ch){
        return links[ch-'a'];
    }
    // set end value to true once word is over
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
    
    private: 
    Node* root;
    Node* searchRoot;
    int flag;
    string str;
    
    public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
        flag = 0;
        str = "";
        searchRoot = root;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    void putRemain(Node* node, vector<string> &arr, string str){
        
        if(arr.size() >= 3) return; 
        
        if(node->isEnd()){
            arr.push_back(str);
        }
        for(int i=0; i<26; i++){
            
            if(node->containsKey(char(i+'a'))){
                str += char(i+'a');
                Node* newNode = node->get(char(i+'a'));
                putRemain(newNode, arr, str);
                str.pop_back();
            }
        }
    }
    
    vector<string> f(int i, string s){
        
        vector<string> arr;
        
        if(!searchRoot->containsKey(s[i]) || flag == 1){
            flag = 1;
            return {};
        }
        
        str += s[i];
        searchRoot = searchRoot->get(s[i]);
           
        putRemain(searchRoot, arr, str);
        
        // while(arr.size() > 3){
        //     arr.pop_back();
        // }
        return arr;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        Trie* trie = new Trie();
        for(auto i: products){
            trie->insert(i);
        }
        vector<vector<string>> str;
        for(int i=0; i<searchWord.size(); i++){
            str.push_back(trie->f(i, searchWord));
        }
        return str;
    }
};