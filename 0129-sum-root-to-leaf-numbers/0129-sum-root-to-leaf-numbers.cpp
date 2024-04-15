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
    
    void f(TreeNode* root, string str, int &ans){
        
        if(!root) return;
        if(!root->left and !root->right){
            str += char(root->val + '0');
            ans += stoi(str);
            return;
        }
        f(root->left, str+char(root->val + '0'), ans);
        f(root->right, str+char(root->val + '0'), ans);
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        
        int ans = 0;
        string str;
        f(root, str, ans);
        return ans;
    }
};