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
    int ans = 0;
public:
    
    vector<int> f(TreeNode* root){
        
        if(!root) return {INT_MAX, INT_MIN, 0};
        
        vector<int> left = f(root->left);
        vector<int> right = f(root->right);
        bool curr = (root->val > left[1] && root->val < right[0]);
        int currSum = -10000;
        
        if(curr){
            
            currSum = left[2] + right[2] + root->val;
            ans = max(ans, left[2] + right[2] + root->val);
            int currMin = min(root->val, left[0]);
            int currMax = max(root->val, right[1]);
            
            return { currMin, currMax, currSum };
        
        }else return { INT_MIN, INT_MAX, currSum };
        
    }
    
    int maxSumBST(TreeNode* root) {
        
        f(root);
        return ans;
    }
};