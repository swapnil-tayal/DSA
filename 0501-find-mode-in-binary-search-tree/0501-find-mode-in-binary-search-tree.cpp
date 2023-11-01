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
    map<int,int> mp;
public:
    
    void dfs(TreeNode* node){
        if(!node) return;
        mp[node->val]++;
        dfs(node->left);
        dfs(node->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        
        dfs(root);
        int maxi = 0;
        for(auto i: mp) maxi = max(maxi, i.second);
        vector<int> ans;
        for(auto i: mp) if(i.second == maxi) ans.push_back(i.first);
        return ans;
    }
};