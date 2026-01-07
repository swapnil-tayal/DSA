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

    long long f(TreeNode* root){
        if(!root) return 0;
        long long currSum = root->val + f(root->left) + f(root->right);
        ans = max(ans, (sum - currSum) * currSum);
        return currSum;
    }

    int maxProduct(TreeNode* root) {
        sum = f(root);
        f(root);
        return ans % int(1e9+7);
    }
};