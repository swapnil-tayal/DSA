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
    
    int f(TreeNode* root, vector<int> &arr){
        
        if(!root) return 0;
        if(!root->left and !root->right){
            
            arr[root->val]++;
            int cnt = 0;
            // for(auto k: arr) cout<<k<<' ';
            // cout<<'\n';
            for(auto k: arr) cnt += (k%2);
            arr[root->val]--;
            return cnt <= 1;
        }
        
        arr[root->val]++;
        int left = f(root->left, arr);
        int right = f(root->right, arr);
        arr[root->val]--;
        return left + right;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> arr(10, 0);
        return f(root, arr);
    }
};