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
    
    bool f(TreeNode* root, long mini, long maxi){
        
        if(!root) return true;
        if(!(root->val > mini && root->val < maxi)) return false;
        
        int left = f(root->left, mini, min(maxi, (long)root->val));
        int right = f(root->right, max(mini, (long)root->val), maxi);
        return left && right;
    }
    
    bool isValidBST(TreeNode* root) {
        return f(root, LONG_MIN, LONG_MAX);
    }
};