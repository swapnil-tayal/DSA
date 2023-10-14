class Solution {
    int n;
public:
    
    int f(int i, vector<int> &cost, vector<int> &time, int cnt, vector<vector<int>> &dp){
        
        if(i == time.size()){
            if(cnt >= 0) return 0;
            return 1e9;
        }
        if(dp[i][cnt+n] != -1) return dp[i][cnt+n];
         
        int pick = cost[i] + f(i+1, cost, time, min(n, cnt + time[i]), dp);
        int npcik = f(i+1, cost, time, cnt-1, dp);
        
        return dp[i][cnt+n] =  min(pick, npcik);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        this->n = cost.size();
        vector<vector<int>> dp(n, vector<int>(2*n+1, -1));
        return f(0, cost, time, 0, dp);
    }
};