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
    
    string f(TreeNode* root){
        
        if(!root) return "";
        if((!root->left and !root->right)) return to_string(root->val);
        
        string str = "";
        str += to_string(root->val);
        
        string left = f(root->left);
        string right = f(root->right);
        
        if(right == "") return str + "(" + left + ")" ;
        else return str + "(" + left + ")" + "(" + right + ")";
    }
    
    string tree2str(TreeNode* root) {
        return f(root);
    }
};