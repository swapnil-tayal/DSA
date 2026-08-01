class Solution {
    vector<vector<vector<int>>> dp;
public:

    int f(int i, int j, int p1, vector<int> &nums){

        if(i > j) return 0;
        if(dp[i][j][p1] != -1) return  dp[i][j][p1];
        if(p1){

            int left = nums[i] + f(i+1, j, 1-p1, nums);
            int right = nums[j] + f(i, j-1, 1-p1, nums);
            return dp[i][j][p1] = max(left, right);

        }else{

            int left = -nums[i] + f(i+1, j, 1-p1, nums);
            int right = -nums[j] + f(i, j-1, 1-p1, nums);
            return dp[i][j][p1] = min(left, right);

        }
    }

    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return f(0, n-1, 1, nums) >= 0;
    }
};