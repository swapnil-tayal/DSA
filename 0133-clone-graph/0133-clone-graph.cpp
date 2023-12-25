/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution{
    map<int, Node*> mp;
    map<int, Node*> org;
public:
    
    void dfs(Node* node){
        
        if(!node) return;
        
        mp[node->val] = new Node(node->val);
        org[node->val] = node;
        for(auto i: node->neighbors){
            if(i and mp.find(i->val) != mp.end()) continue;
            dfs(i);
        }
    }
    
    Node* cloneGraph(Node* node) {
        
        dfs(node);
        
        for(auto i: org){
            for(auto node: i.second->neighbors){
                mp[i.first]->neighbors.push_back(mp[node->val]);
            }
        }
        return mp[1];
    }
};