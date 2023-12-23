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
    int ans = -1e9;
public:
    
    int f(TreeNode* root){
        
        if(!root) return 0;
        
        int left = f(root->left);
        int right = f(root->right);
        
        int maxCurr = max({ root->val, max(left, right) + root->val });
        ans = max({ans, maxCurr, root->val + left + right});
        return maxCurr;
    }
    
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};