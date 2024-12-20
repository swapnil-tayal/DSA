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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<TreeNode*>> mat;
        mat.push_back({root});
        int cnt = 1;
        while(!q.empty()){
            
            int n = q.size();
            
            vector<TreeNode*> a;
            cnt++;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    a.push_back(node->left);
                    node->left = NULL;
                }
                if(node->right){
                    q.push(node->right);
                    a.push_back(node->right);
                    node->right = NULL;
                }
            }
            if(cnt%2 == 0) reverse(a.begin(), a.end());
            if(a.size()) mat.push_back(a);
        }
        
        map<pair<int,int>, TreeNode*> mp;
        mp[{0,0}] = new TreeNode(root->val);
        
        for(int i=0; i<mat.size()-1; i++){
            for(int j=0; j<mat[i].size(); j++){
                
                mp[{i,j}]->left = new TreeNode(mat[i+1][2*j]->val);
                mp[{i,j}]->right = new TreeNode(mat[i+1][(2*j) + 1]->val);
                mp[{i+1, 2*j}] = mp[{i, j}]->left;
                mp[{i+1, (2*j) + 1}] = mp[{i, j}]->right;
            }
        }
        return mp[{0,0}];
    }
};