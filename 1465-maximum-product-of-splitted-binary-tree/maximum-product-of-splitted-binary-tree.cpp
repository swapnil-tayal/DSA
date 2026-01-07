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
    long long sum = 0;
    long long ans = 0;
public:

    long long getTotSum(TreeNode* root){
        if(root == NULL) return 0;
        long long sum = root->val;
        if(root->left) sum += getTotSum(root->left);
        if(root->right) sum += getTotSum(root->right);
        return sum;
    }

    long long f(TreeNode* root){
        if(root == NULL) return 0;
        long long currSum = root->val;
        if(root->left) currSum += f(root->left);
        if(root->right) currSum += f(root->right);
        long long rem = sum - currSum;
        ans = max(ans, rem * currSum);
        return currSum;
    }

    int maxProduct(TreeNode* root) {
        
        sum = getTotSum(root);
        f(root);
        return (ans) % int(1e9+7);
    }
};