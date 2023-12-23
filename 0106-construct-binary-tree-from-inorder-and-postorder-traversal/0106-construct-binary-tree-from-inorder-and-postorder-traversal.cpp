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
    
    TreeNode* f(int postS, int indS, int indE, vector<int> &postorder){
        
        if(indS > indE || (postS < 0 || postS >= postorder.size())) return NULL;
        TreeNode* root = new TreeNode(postorder[postS]);
        int ind = inD[postorder[postS]];
        
        int leftSize = ind - indS;
        int rightSize = indE - ind;
        
        root->left = f(postS-rightSize-1, indS, ind-1, postorder);
        root->right = f(postS-1, ind+1, indE, postorder);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inD[inorder[i]] = i; 
        }
        return f(n-1, 0, n-1, postorder);
        
    }
};