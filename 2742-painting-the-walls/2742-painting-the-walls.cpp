class Solution {
    int n;
public:
    
    int f(int i, vector<int> &cost, vector<int> &time, int cnt, vector<vector<int>> &dp){
        
        if(cnt >= n) return 0;
        if(i == time.size()){
            if(cnt >= n) return 0;
            return 1e9;
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
         
        int pick = cost[i] + f(i+1, cost, time, 1 + cnt + time[i], dp);
        int npcik = f(i+1, cost, time, cnt, dp);
        
        return dp[i][cnt] =  min(pick, npcik);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        this->n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, cost, time, 0, dp);
    }
};