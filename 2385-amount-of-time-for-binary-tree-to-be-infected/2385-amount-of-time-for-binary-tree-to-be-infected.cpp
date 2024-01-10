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
class Solution{
    TreeNode* node;
    
    map<TreeNode*, TreeNode*> mp;
    void f(TreeNode* src, TreeNode* par, int start){
        
        if(!src) return;
        mp[src] = par;
        if(src->val == start){
            node = src;
        }
        f(src->left, src, start);
        f(src->right, src, start);
    }
    
public:
    int amountOfTime(TreeNode* root, int start) {
        
        f(root, NULL, start);
        int cnt = 0;
        
        queue<TreeNode*> q;;
        q.push(node);
        set<TreeNode*> st;
        st.insert(node);
        
        while(!q.empty()){
            
            int n = q.size();
            while(n--){
                
                TreeNode* node = q.front();
                st.insert(node);
                q.pop();
                TreeNode* top = mp[node];
                TreeNode* left = node->left;
                TreeNode* right = node->right;
                
                if(top and st.count(top) == 0) q.push(top);
                if(left and st.count(left) == 0) q.push(left);
                if(right and st.count(right) == 0) q.push(right);
            }
            cnt++;
        }
        return cnt-1;
    }
};