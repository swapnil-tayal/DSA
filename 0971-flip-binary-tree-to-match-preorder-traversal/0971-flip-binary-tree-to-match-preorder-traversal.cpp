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
    vector<int> ans;
public:
    
    int f(int i, int j, TreeNode* root, vector<int> &arr){
        
        if(!root) return 1;
        if(!root->left and !root->right){
            if(i > j || arr[i] != root->val) return 0;
            else return 1;
        }
        if(arr[i] != root->val) return 0;
        
        if(root->left and root->right){
            int left = 0;
            int right = 0;
            
            if(arr[i+1] == root->left->val){
                
                int ind = i;
                while(ind<=j and arr[ind] != root->right->val) ind++;
                if(ind <= j){
                    right = f(ind, j, root->right, arr);
                    left = f(i+1, ind-1, root->left, arr);
                }
                
            }else if(arr[i+1] == root->right->val){
                
                ans.push_back(root->val);
                int ind = i;
                while(ind <= j and arr[ind] != root->left->val) ind++;
                if(ind < arr.size()){
                    right = f(i+1, ind-1, root->right, arr);
                    left = f(ind, j, root->left, arr);
                }
            }
            return left && right;
            
        }else if(root->left){
            
            if(arr[i+1] != root->left->val) return 0;
            else return f(i+1, j, root->left, arr);
        
        }else if(root->right){
            
            if(i+1 <= j && arr[i+1] != root->right->val) return 0;
            else return f(i+1, j, root->right, arr);
        }   
        return 0;
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        
        int n = voyage.size();
        int res = f(0, n-1, root, voyage);
        if(res == 0) return {-1};
        else return ans;
    }
};