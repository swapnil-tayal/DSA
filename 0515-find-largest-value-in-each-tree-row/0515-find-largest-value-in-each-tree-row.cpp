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
    vector<int> largestValues(TreeNode* root) {
        
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> arr;
        
        while(!q.empty()){
            
            int n = q.size();
            long long maxi = -1e10;
            
            while(n--){
                
                TreeNode* node = q.front();
                maxi = max(maxi, (long long)node->val); 
                q.pop();
                
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
            arr.push_back(maxi);
        }
        return arr;
    }
};