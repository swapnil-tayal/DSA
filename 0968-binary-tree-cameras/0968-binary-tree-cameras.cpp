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
    TreeNode* node;
public:
    
    int f(TreeNode* root, int needCov, int needCam, map<pair<TreeNode*, pair<int,int>> ,int> &dp){
        
        if(!root){
            if(needCam) return 1e9;
            return 0;
        }
        if(dp.find({root, {needCov, needCam}}) != dp.end()) return dp[{root, {needCov, needCam}}];
        if(needCov){
            
            int leftCam = f(root->left, 0, 1, dp) + f(root->right, 1, 0, dp);
            int rightCam = f(root->left, 1, 0, dp) + f(root->right, 0, 1, dp);
            int bothSide = f(root->left, 0, 1, dp) + f(root->right, 0, 1, dp);
            int placeCam = 1 + f(root->left, 0, 0, dp) + f(root->right, 0, 0, dp);
            // if(root == node) cout<<bothSide<<' '<<placeCam<<'\n';
            return dp[{root, {needCov, needCam}}] = min({ leftCam, rightCam, bothSide, placeCam });
            
        }else if(needCam){
            
            int ans = 1 + f(root->left, 0, 0, dp) + f(root->right, 0, 0, dp);
            return dp[{root, {needCov, needCam}}] = ans;
            
        }else{
            
            int pass = f(root->left, 1, 0, dp) + f(root->right, 1, 0, dp);
            int palceCam = 1 + f(root->left, 0, 0, dp) + f(root->right, 0, 0, dp);
            return dp[{root, {needCov, needCam}}] = min({ pass, palceCam });
        }
    }
    
    int minCameraCover(TreeNode* root) {
        node = root;
        map<pair<TreeNode*, pair<int,int>> ,int> dp;
        return f(root, 1, 0, dp);
    }
};