class Solution {
    vector<vector<int>> cost;
public:

    int f(int i, vector<int> &houses, int n, int target, int prevColor, vector<vector<vector<int>>> &dp){

        if(i == houses.size()){
            if(target == 0) return 0;
            else return 1e9;
        }
        if(target < 0) return 1e9;
        if(dp[i][target][prevColor+1] != -1) return dp[i][target][prevColor+1];

        int ans = 1e9;
        if(houses[i] != 0){

            ans = f(i+1, houses, n, houses[i] != prevColor ? target-1: target, houses[i], dp);

        }else{

            for(int k=1; k<=n; k++){
                int price = cost[i][k-1];
                int currColorCost = price + f(i+1, houses, n, prevColor != k ? target-1 : target, k, dp);
                ans = min(ans, currColorCost);
            }

        }
        return dp[i][target][prevColor+1] = ans;
    }    

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

        this->cost = cost;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(target+1, vector<int>(n+2, -1)));
        int ans = f(0, houses, n, target, -1, dp);
        return ans == 1e9 ? -1 : ans;
    }
};