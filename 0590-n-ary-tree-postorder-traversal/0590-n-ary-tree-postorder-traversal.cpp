/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> arr;
public:
    
    void f(Node* root){
        
        if(!root) return;
        for(auto i: root->children) f(i);
        arr.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        
        f(root);
        return arr;
    }
};