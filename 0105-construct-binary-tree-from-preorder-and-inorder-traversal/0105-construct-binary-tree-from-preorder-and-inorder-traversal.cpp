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
    map<int,int> inD;
public:
    
    TreeNode* f(int ps, int pe, int is, int ie, vector<int> &preorder){
        
        if(is > ie || ps > pe) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int ind = inD[preorder[ps]];
        
        int leftSize = ind - is;
        int rightSize = ie - ind;
        
        root->left = f(ps+1, ps+leftSize, is, ind-1, preorder);
        root->right = f(ps+leftSize+1, ps+leftSize+rightSize, ind+1, ie, preorder);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inD[inorder[i]] = i; 
        }
        return f(0, 0, 0, n-1, preorder);
    }
};