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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> st;
        
        for(auto &i: descriptions){

            int par = i[0];
            int child = i[1];
            int isLeft = i[2];

            st.insert(child);

            if(!mp.count(par)){
                mp[par] = new TreeNode(par);
            }
            if(!mp.count(child)) {
                mp[child] = new TreeNode(child);
            }
            if(isLeft) mp[par]->left = mp[child];
            else mp[par]->right = mp[child];

        }
        for(auto &i: descriptions){
            if(st.count(i[0]) == 0) return mp[i[0]];
        }
        return NULL;
    }
};