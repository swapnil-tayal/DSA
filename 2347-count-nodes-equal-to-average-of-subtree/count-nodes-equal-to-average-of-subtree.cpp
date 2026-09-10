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
    int ans;
public:
    
    pair<int,int> dfs(TreeNode* root){
        
        if(!root) return {0,0};
        
        int cnt = 0;
        int sum = 0;
        auto x1 = dfs(root->left);
        auto x2 = dfs(root->right);
        
        cnt += x1.first + x2.first + 1;
        sum += x1.second + x2.second + root->val;
        
        if(sum/cnt == root->val) ans++;
        return {cnt, sum};
    }
    
    int averageOfSubtree(TreeNode* root) {
        
        this->ans = 0;
        dfs(root);
        return ans;
    }
};