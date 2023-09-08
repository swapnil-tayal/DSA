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
    
    map<string, vector<TreeNode*>> mp;
    vector<TreeNode*> ans;
public:
    
    string f(TreeNode* root){
        
        if(!root) return "#";
        string s1 = f(root->left);
        string s2 =f(root->right);
        
        string str;
        str += "(";
        str += to_string(root->val);
        str += s1;
        str += s2;
        str += ')';
        
        mp[str].push_back(root);
        if(mp[str].size() == 2) ans.push_back(root);
        return str;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        f(root);
        return ans;
    }
};