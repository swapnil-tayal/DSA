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
    
    TreeNode* f(int preS, int indS, int indE, vector<int> &preorder){
        
        if(indS > indE || preS < 0) return NULL;
        TreeNode* root = new TreeNode(preorder[preS]);
        int ind = inD[preorder[preS]];
        
        int leftSize = ind - indS;
        int rightSize = indE - ind;
        
        root->left = f(preS+1, indS, ind-1, preorder);
        root->right = f(preS+leftSize+1, ind+1, indE, preorder);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inD[inorder[i]] = i; 
        }
        return f(0, 0, n-1, preorder);
    }
};