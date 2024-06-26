
class Solution {
public:
    
    void solve(vector<int> &arr, TreeNode* root){
        if(!root) return;
        
        solve(arr, root->left);
        arr.push_back(root->val);
        solve(arr, root->right);
        return;
    }
    
    TreeNode* solve2(vector<int> &arr, int s, int e){
        if(s > e){
            return NULL;
        }
        
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = solve2(arr, s, mid-1);
        root->right = solve2(arr, mid+1, e);
        return root;
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        solve(arr, root);
        
        return solve2(arr, 0, arr.size()-1);
    }
};