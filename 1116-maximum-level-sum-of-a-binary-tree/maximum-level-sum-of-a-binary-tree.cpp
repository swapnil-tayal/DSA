class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        long long maxSum = root->val;
        int lvl = 1;
        int ans = 1;
        long long sum = root->val;

        while(!q.empty()){

            int k = q.size();
            if(maxSum < sum){
                maxSum = sum;
                ans = lvl;
            }
            lvl++;
            sum = 0;
            while(k--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                    sum += node->left->val;
                }
                if(node->right != NULL){
                    q.push(node->right);
                    sum += node->right->val;
                }
            }
        }
        return ans;
    }
};