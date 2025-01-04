class Solution {
public:
    // swapnil
    int f(int i, vector<int> &arr, vector<int> &costs,int curr, vector<vector<int>> &dp){
        
        if(i == arr.size()) return 0;
        if(dp[i][curr] != -1) return dp[i][curr];
        
        if(arr[i] < curr){
            return dp[i][curr] = f(i+1, arr, costs, curr, dp);
        }else{
            int one = costs[0] + f(i+1, arr, costs, arr[i]+1, dp);
            int teo = costs[1] + f(i+1, arr, costs, arr[i]+7, dp);
            int three = costs[2] + f(i+1, arr, costs, arr[i]+30, dp);
            return dp[i][curr] = min(one, min(teo, three));
        }
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        vector<vector<int>> dp(n, vector<int>(365+31, -1));
        return f(0, days, costs, 0, dp);
    }
};