class Solution {
public:
    
    int f(int i, int n, vector<int> &obstacles, int currLane, vector<vector<int>> &dp){
        
        if(i == n) return 0;
        if(obstacles[i] == currLane) return 1e9;
        if(dp[i][currLane] != -1) return dp[i][currLane];
        
        if(currLane == 1){
            int up = 0 + f(i+1, n, obstacles, 1, dp); 
            
            int mid = 1e9;
            if(obstacles[i] != 2) mid = 1 + f(i+1, n, obstacles, 2, dp); 
            
            int down = 1e9;
            if(obstacles[i] != 3) down = 1 + f(i+1, n, obstacles, 3, dp);
            
            return dp[i][currLane] = min(up, min(mid, down));
           
        }else if(currLane == 2){
            int up = 1e9;
            if(obstacles[i] != 1) up = 1 + f(i+1, n, obstacles, 1, dp);
            
            int mid = 0 + f(i+1, n, obstacles, 2, dp);   
            
            int down = 1e9;
            if(obstacles[i] != 3) down = 1 + f(i+1, n, obstacles, 3, dp);
            
            return dp[i][currLane] = min(up, min(mid, down));
        
        }else{
            int up = 1e9;
            if(obstacles[i] != 1) up = 1 + f(i+1, n, obstacles, 1, dp);
            
            int mid = 1e9;
            if(obstacles[i] != 2) mid = 1 + f(i+1, n, obstacles, 2, dp);  
            
            int down = 0 + f(i+1, n, obstacles, 3, dp); 
            return dp[i][currLane] = min(up, min(mid, down));         
            
        }
    }
    
    int minSideJumps(vector<int>& obstacles) {
        
        int n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(0, n, obstacles, 2, dp);
    }
};