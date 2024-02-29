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
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return true;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            vector<int> arr;
            for(int i=0; i<n; i++){
                TreeNode* front = q.front();
                q.pop();
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                arr.push_back(front->val);
            }
            ans.push_back(arr);
        }
        for(int i=0; i<ans.size(); i++){
            vector<int> v = ans[i];
            if(i%2 == 0){   
                for(auto j: v){
                    if(j%2 == 0) return false;
                }
                for(int j=0; j<v.size()-1; j++){
                    if(v[j] >= v[j+1]) return false;
                }
            }
            else{
                for(auto j: v){
                    if(j%2 != 0) return false;
                }
                for(int j=0; j<v.size()-1; j++){
                    if(v[j] <= v[j+1]) return false;
                }
            }
        }
        return true;
    }
};