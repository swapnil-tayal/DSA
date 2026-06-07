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
        
        map<int, TreeNode*> mp;
        set<int> st;
        vector<int> temp;
        for(auto &i: descriptions){

            int par = i[0];
            int child = i[1];
            int isLeft = i[2];

            st.insert(par);
            temp.push_back(child);

            if(!mp.count(par)){
                mp[par] = new TreeNode(par);
            }
            if(!mp.count(child)) {
                mp[child] = new TreeNode(child);
            }
            if(isLeft) mp[par]->left = mp[child];
            else mp[par]->right = mp[child];

        }
        for(auto &i: temp) st.erase(i);
        return mp[*st.begin()];
    }
};