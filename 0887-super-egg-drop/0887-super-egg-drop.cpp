class Solution {
public:
    
    int f(int n, int k, vector<vector<int>> &dp){
        
        if(n == 1) return 1;
        if(n == 0) return 0;
        if(k == 1) return n;
        
        if(dp[n][k] != -1) return dp[n][k];
        int ans = 1e9;
        
//      binary traversal
        int s = 0;
        int e = n;
        while(s <= e){
            
            int mid = (s+e)/2;
            int broken = 1 + f(mid-1, k-1, dp);
            int nbroken = 1 + f(n-mid, k, dp);
            ans = min(ans, max(broken, nbroken));
            
            if(broken > nbroken) e = mid-1;
            else s = mid+1;
        }
        return dp[n][k] = ans;
        
//         liner traversal
//         for(int i=1; i<=n; i++){
            
//             int broken = 1 + f(i-1, k-1, dp);
//             int nbroken = 1 + f(n-i, k, dp);
//             int f = max(broken, nbroken);
//             ans = min(ans, f);
//         }
//         return dp[n][k] = ans;
    }
    
    int superEggDrop(int k, int n) {
        
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return f(n, k, dp);
    }
};