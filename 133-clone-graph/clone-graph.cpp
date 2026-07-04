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

class Solution {

    map<int, Node*> mp;
public:

    Node* getClone(int val){

        Node* cloneNode;
        if(mp.find(val) != mp.end()) cloneNode = mp[val];
        else{
            mp[val] = new Node(val);
            cloneNode = mp[val];
        }
        return cloneNode;
    }

    void f(Node* node, vector<int> &vis){

        vis[node->val] = 1;
        Node* cloneNode = getClone(node->val);

        for(auto &i: node->neighbors){

            Node* cloneChild = getClone(i->val);
            cloneNode->neighbors.push_back(cloneChild);
            if(vis[i->val]) continue;
            f(i, vis);
        }
        return;
    }

    Node* cloneGraph(Node* node) {
        
        if(node == NULL) return NULL;
        vector<int> vis(101);
        f(node, vis);
        return mp[node->val];
    }
};