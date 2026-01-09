/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxDepth = -1;
    vector<TreeNode*> nodes;
    map<TreeNode*, TreeNode*> mp;
    map<TreeNode*, int> depth;
public:

    void f(int lvl, TreeNode* root, TreeNode* par){
        
        if(!root) return;
        mp[root] = par;
        depth[root] = lvl;
        if(lvl > maxDepth){
            nodes = vector<TreeNode*>();
            maxDepth = lvl;
            nodes.push_back(root);
        }else if(lvl == maxDepth) nodes.push_back(root);
        
        if(root->left) f(lvl+1, root->left, root);
        if(root->right) f(lvl+1, root->right, root);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        f(0, root, NULL);
        
        map<pair<TreeNode*,int>, int> mp2;
        for(auto &i: nodes){
            TreeNode* node = i;
            while(node != NULL) {
                mp2[{ node, depth[node] }]++;
                node = mp[node];
            }
        }
        TreeNode* ans = NULL;
        int minDepth = -1e9;
        for(auto &i: mp2){
            if(i.second == nodes.size() && i.first.second > minDepth){
                minDepth = i.first.second;
                ans = i.first.first;
            }
        }
        return ans;   
    }
};