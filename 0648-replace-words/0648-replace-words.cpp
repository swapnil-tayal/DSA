struct Node{
    
    Node* links[26];
    bool flag = false;

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
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
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
    
    string f(string sentence){
        
        vector<string> str;
        string temp = "";
        for(int i=0; i<sentence.size(); i++){
            
            if(i == sentence.size()-1){
                temp += sentence[i];
                str.push_back(temp);
                continue;
            }
            
            if(sentence[i] == ' '){
                str.push_back(temp);
                temp = "";
                continue;
            }
            temp = temp + sentence[i];
        }
        
        string ans = "";
        
        for(auto i: str){
            
            Node* node = root;
            int f = 1;
            
            // if(i.size() == 1){
            //     ans += i + " ";
            //     continue;
            // }
            
            for(int j=0; j<i.size() and f==1; j++){
                
                if(j == i.size()-1){
                    ans += i + " ";
                    break;
                }
                
                if(node->containsKey(i[j]) and f==1){
                    
                    node = node->get(i[j]);
                    if(node->flag == true){
                        ans += i.substr(0, j+1);
                        ans += " ";
                        f=0;;
                    }
                
                }else{
                    ans += i;
                    ans += " ";
                    f=0;
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        
        Trie* root = new Trie();
        for(auto i: dictionary){
            root->insert(i);
        }        
        return root->f(sentence);
    }
};