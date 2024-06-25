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
    
    int s = 0;
    
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->right);
        
        root->val = s + root->val;
        s = root->val;
        
        solve(root->left);
        return;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return NULL;
        solve(root);
        return root;
    }
};