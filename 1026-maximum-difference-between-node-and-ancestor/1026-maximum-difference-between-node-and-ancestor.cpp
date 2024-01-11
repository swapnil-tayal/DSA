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
class Solution{
    int ans;
public:
    
    pair<int,int> f(TreeNode* root){
        
        if(!root) return { 1e9, -1e9 };
        if(!root->left and !root->right) return { root->val, root->val };
        
        pair<int,int> left = f(root->left);
        pair<int,int> right = f(root->right);
        
        int mini = min(left.first, right.first);
        int maxi = max(left.second, right.second);
        
        // if(root->val == 0){
            // cout<<mini<<' '<<maxi<<'\n';
            // cout<<max({ abs(mini - root->val), abs(maxi - root->val) })<<'\n';
        // }
        ans = max({ ans,  abs(mini - root->val), abs(maxi - root->val) });
        return { min(mini, root->val), max(maxi, root->val) };
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        this->ans = 0;
        f(root);
        return ans;
    }
};






