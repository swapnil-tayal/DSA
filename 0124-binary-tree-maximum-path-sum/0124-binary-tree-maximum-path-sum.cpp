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
    
    int f(TreeNode* root, int x, map<pair<TreeNode*,int>, int> &dp){
        
        if(!root){
            if(x == 0) return -1e9;
            return 0;
        }
        if(dp.find({root, x}) != dp.end()) return dp[{root, x}];
        
        if(x == 0){
            
            int npick1 = f(root->left, 0, dp);
            int npick2 = f(root->right, 0, dp);
            int pick1 = root->val + f(root->left, 1, dp);
            int pick2 = root->val + f(root->right, 1, dp);
            int pick3 = root->val + f(root->left, 1, dp) + f(root->right, 1, dp);
            return dp[{root, x}] = max({pick1, pick2, pick3, npick1, npick2});
            
        }else if(x == 1){
            
            int pick1 = root->val + f(root->left, 1, dp);
            int pick2 = root->val + f(root->right, 1, dp);
            // int pick3 = root->val + f(root->left, 1, dp) + f(root->right, 1, dp);
            int npick = f(root->left, 2, dp) + f(root->right, 2, dp);
            return dp[{root, x}] = max({pick1, pick2, npick});
            
        }else{
            return dp[{root, x}] = 0;
        }
    }
    
    int maxPathSum(TreeNode* root) {
        
        map<pair<TreeNode*,int>, int> dp;
        return f(root, 0, dp);
    }
}; 