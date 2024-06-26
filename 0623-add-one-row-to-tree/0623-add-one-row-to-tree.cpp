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
    
    TreeNode* addOneRow(TreeNode* node, int val, int depth) {
        
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = node;
            return newNode;
        }
        if(!node) return NULL;
        
        if(depth == 2){
            TreeNode* leftNode = NULL;
            TreeNode* rightNode = NULL;
            if(node->left) leftNode = node->left;
            if(node->right) rightNode = node->right;
            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            node->left->left = leftNode;
            node->right->right = rightNode;
            return node;
        }
        TreeNode* root = new TreeNode(node->val);
        root->left = addOneRow(node->left, val, depth-1);
        root->right = addOneRow(node->right, val, depth-1);
        
        return root;
    }
};