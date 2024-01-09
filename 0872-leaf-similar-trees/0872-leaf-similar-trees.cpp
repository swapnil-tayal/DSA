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
public:
    
    void f(TreeNode* root, vector<int> &leaf){
        
        if(!root) return;
        if(!root->left and !root->right){
            leaf.push_back(root->val);
        }
        f(root->left, leaf);
        f(root->right, leaf);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> a1, a2;
        f(root1, a1);
        f(root2, a2);
        return a1 == a2;
    }
};