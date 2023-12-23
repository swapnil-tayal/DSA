/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        
        TreeNode* l = NULL;
        TreeNode* r = NULL;
        if(p->val <= root->val && q->val <= root->val) l = lowestCommonAncestor(root->left, p, q);
        else if(p->val >= root->val && q->val >= root->val) r = lowestCommonAncestor(root->right, p, q);
        else return root;
        
        if(l && r){
            return root;
        }else if(!l && r){
            return r;
        }else if(!r && l){
            return l;
        }else{
            return NULL;
        }
    }
};