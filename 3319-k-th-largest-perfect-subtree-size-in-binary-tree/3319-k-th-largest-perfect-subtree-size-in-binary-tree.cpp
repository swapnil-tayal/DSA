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
    vector<int> a;
public:
    
    pair<int,int> f(TreeNode* root){
        
        if(!root) return {0, 1};
        
        pair<int,int> left = f(root->left);
        pair<int,int> right = f(root->right);
        
//         cout<<root->val<<' '<<left.second <<' '<<right.second<<'\n';
        
        if(left.first == right.first and left.second == right.second && right.second == 1){
            a.push_back(left.first+1);
            return {left.first+1, 1};
        }else{
            return {left.first+1, 0};
        }
    }
    
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        
        f(root);
        sort(a.rbegin(), a.rend());
        
        // for(auto i: a) cout<<i<<' ';
        // cout<<'\n';
        
        vector<int> p;
        p.push_back(1);
        for(int i=1; i<20; i++){
            p.push_back(pow(2, i) + p.back());
        }
        if(a.size() < k) return -1;
        else{
            cout<<a[k-1]<<' ';
            return p[a[k-1]-1];
        }
    }
};