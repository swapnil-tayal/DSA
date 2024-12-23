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
    
    int minSwaps(vector<int> nums, int n)
    {
        int len = n;
        map<int, int> map;
        for (int i = 0; i < len; i++)
            map[nums[i]] = i;

        sort(nums.begin(), nums.end());

        // To keep track of visited elements. Initialize
        // all elements as not visited or false.
        vector<int> visited(len, 0);

        // Initialize result
        int ans = 0;
        for (int i = 0; i < len; i++) {

            // already swapped and corrected or
            // already present at correct pos
            if (visited[i] || map[nums[i]] == i)
                continue;

            int j = i, cycle_size = 0;
            while (!visited[j]) {
                visited[j] = true;

                // move to next node
                j = map[nums[j]];
                cycle_size++;
            }

            // Update answer by adding current cycle.
            if (cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }
    
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> mat;
        mat.push_back({root->val});
        int ans = 0;
        
        while(!q.empty()){
            
            int n = q.size();
            
            vector<int> a;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    a.push_back(node->left->val);
                    node->left = NULL;
                }
                if(node->right){
                    q.push(node->right);
                    a.push_back(node->right->val);
                    node->right = NULL;
                }
            }
            ans += minSwaps(a, a.size());
        }
        return ans;
    }
};