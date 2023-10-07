class Solution{
    int n;
    const int mod = 1000000007;
public:
    
    int f(int i, int k, int currMax, int m, vector<vector<vector<int>>> &dp){
        
        if(i == n) return k==0;
        if(dp[i][k][currMax] != -1) return dp[i][k][currMax];
        
        if(k > 0){
            
            int grt = 0;
            for(int j=currMax+1; j<=m; j++){
                grt = (grt + f(i+1, k-1, j, m, dp)) % mod;
            }
            int makeSmall = 0;
            for(int j=1; j<=currMax; j++){
                makeSmall = (makeSmall + f(i+1, k, currMax, m, dp)) % mod; 
            }
            return dp[i][k][currMax] = (grt + makeSmall) % mod;
        
        }else{
            int makeSmall = 0;
            for(int j=1; j<=currMax; j++){
                makeSmall = (makeSmall + f(i+1, k, currMax, m, dp)) % mod; 
            }
            return dp[i][k][currMax] = makeSmall;
        }
    }
    
    int numOfArrays(int n, int m, int k) {
        
        this->n = n;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(m+1, -1)));
        return f(0, k, 0, m, dp);
    }
};