class Solution {
public:
    
    int f(int ind, int k, string ring, string key, vector<vector<int>> &dp){
        
        if(k == key.size()) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];
        
        int ans = 1e9;
        for(int i=0; i<ring.size(); i++){
            
            int v = ring.size();
            int currInd = (ind+i) % v;
            int currInd2 = (v + ind - i) % v; 
            
            char ch = ring[currInd];
            char ch2 = ring[currInd2];
            
            if(ch2 == key[k]){
                ans = min(ans, i+1 + f(currInd2, k+1, ring, key, dp));
            }
            if(ch == key[k]){
                ans = min(ans, i+1 + f(currInd, k+1, ring, key, dp));
            }
        }
        return dp[ind][k] = ans;
    }
    
    int findRotateSteps(string ring, string key) {
        
        int n = ring.size();
        int m = key.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, ring, key, dp);
    }
};