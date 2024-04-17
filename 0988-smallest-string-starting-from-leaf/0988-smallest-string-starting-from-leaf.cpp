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
    string answer = "";
    void solve(TreeNode* root, string temp){
        if(root == NULL){
            return;
        }
        temp = char(root->val + 'a') + temp;
        if(!root->left && !root->right){
            if(answer == ""){
                answer = temp;
            }else{
                answer = min(answer, temp);
            }
        }
        solve(root->left, temp);
        solve(root->right, temp);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        
        if(root == NULL){
            return answer;
        }
        
        solve(root, "");
        return answer;
    }
};