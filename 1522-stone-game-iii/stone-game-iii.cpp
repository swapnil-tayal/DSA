class Solution {
    vector<vector<int>> dp;
public:

    int f(int i, int p1, vector<int> &nums){

        if(i == nums.size()) return 0;
        if(dp[i][p1] != -1 ) return dp[i][p1];
        if(p1){
            int ans = -1e9;
            int score = 0;
            for(int k=i; k<i+3; k++){
                if(k < nums.size()){
                    score += nums[k];
                    ans = max(ans, score + f(k+1, 0, nums));
                }
            }
            return dp[i][p1] = ans;
        }else{
            int ans = 1e9;
            int score = 0;
            for(int k=i; k<i+3; k++){
                if(k < nums.size()){
                    score += nums[k];
                    ans = min(ans, -score + f(k+1, 1, nums));
                }
            }
            return dp[i][p1] = ans;
        }
    }

    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();
        dp.assign(n, vector<int>(2, -1));
        int ans = f(0, 1, stoneValue);
        if(ans == 0) return "Tie";
        else if(ans > 0) return "Alice";
        else return "Bob";
    }
};