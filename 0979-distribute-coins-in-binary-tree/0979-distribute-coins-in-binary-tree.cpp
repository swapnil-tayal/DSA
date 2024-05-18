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
class Solution{
public:
    
    int f(TreeNode* root, int &ans){
        
        if(!root) return 0;
        int right = f(root->right, ans);
        int left = f(root->left, ans);
        ans += abs(left) + abs(right);
        return root->val + right + left - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        
        int ans = 0;
        f(root, ans);
        return ans;
    }
};