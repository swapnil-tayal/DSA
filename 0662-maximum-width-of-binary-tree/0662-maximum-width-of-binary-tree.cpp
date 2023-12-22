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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,unsigned long>> q;
        q.push({root, 1});
        unsigned long ans = 0;
        
        while(!q.empty()){
            
            int n = q.size();
            unsigned long val1 = -1;
            unsigned long val2 = -1;
            
            while(n--){
                
                TreeNode* node = q.front().first;
                unsigned long val = q.front().second;
                q.pop();
                
                if(val1 == -1) val1 = val;
                val2 = val;
                
                if(node->left) q.push({ node->left, val*2 });
                if(node->right) q.push({ node->right, (val*2) + 1 });
                    
            }
            // cout<<val2<<' '<<val1<<'\n';
            ans = max(ans, val2-val1+1);
        }
        return ans;
    }
};