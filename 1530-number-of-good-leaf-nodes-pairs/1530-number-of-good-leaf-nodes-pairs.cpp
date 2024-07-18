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
    
    int count = 0;
    vector<int> solve(TreeNode* root, int distance){
        vector<int> p = {};
        if(root == NULL){
            return p;
        }
        
        vector<int> l = solve(root->right, distance);
        vector<int> r = solve(root->left, distance);
        
        if(l.size() == 0 && r.size() == 0){
            p.push_back(1);
            return p;
        }
        
        for(auto i: l){
            for(auto j: r){
                if(i + j <= distance){
                    count++;
                }
            }
        }
        
        for(auto i: l){
            i++;
            p.push_back(i);
        }for(auto i: r){
            i++;
            p.push_back(i);
        }
        
        return p;
    }
    
    int countPairs(TreeNode* root, int distance) {
        solve(root, distance);
        return count;
    }
};