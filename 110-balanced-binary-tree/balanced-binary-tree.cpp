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
    int ans = 1;
public:

    int f(TreeNode* root){

        if(!root) return 0;
        int left = 0;
        int right = 0;
        if(root->left) left += f(root->left);
        if(root->right) right += f(root->right);
        if(abs(left - right) > 1) ans = false;
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        f(root);
        return ans;
    }
};