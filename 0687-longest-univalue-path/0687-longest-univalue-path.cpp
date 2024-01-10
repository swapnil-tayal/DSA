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
    int ans;
public:
    
    int f(TreeNode* root){
        
        if(!root) return 0;
        
        int left = f(root->left);
        int right = f(root->right);
        
        int x = root->val;
        int currMax = 1;
        if(root->left and root->left->val == x){
            currMax = max(left+1, currMax);
        }
        if(root->right and root->right->val == x){
            currMax = max(right+1, currMax);
        }
        if(root->left and root->right and root->left->val == root->right->val and root->left->val == x){
            ans = max(ans, 1 + left + right);
        }
        ans = max(ans, currMax);
        return currMax;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        this->ans = 0;
        f(root);
        return max(0, ans-1);   
    }
};