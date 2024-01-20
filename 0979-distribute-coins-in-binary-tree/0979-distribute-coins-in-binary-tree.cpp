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
    int ans = 0;
public:
    
    void f(TreeNode* root, TreeNode* par){
        
        if(!root) return;
        
        f(root->left, root);
        f(root->right, root);
        
        if(root->val >= 1){
            
            int coins = abs(1 - root->val);
            root->val = 1;
            ans += coins;
            par->val += coins;
            
        }else{
            
            int coins = abs(1 - root->val);
            root->val = 1;
            ans += coins;
            par->val -= coins;
        }
    }
    
    int distributeCoins(TreeNode* root) {
        
        f(root, root);
        return ans;
    }
};