class Solution{
    const int mod = 1e9+7;
    
    int f(int i, int j, int n, vector<vector<vector<int>>> &dp){

        if(n == 0) return 1;
        
        int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
        int ans = 0;
        if(dp[i][j][n] != -1) return dp[i][j][n];
        
        for(int k=0; k<8; k++){
            int newi = i + dx[k];
            int newj = j + dy[k];
            if(newi >= 0 and newi < 4 and newj >= 0 and newj < 3){
                if(newi == 3 and (newj == 0 || newj == 2)) continue;
                ans = (ans + f(newi, newj, n-1, dp)) % mod;
            }
        }
        return dp[i][j][n] = ans;
    }
    
public:
    int knightDialer(int n) {
        
        int ans = 0;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n, -1)));
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(i == 3 and (j == 0 || j == 2)) continue;
                ans = (ans + f(i, j, n-1, dp)) % mod;
            }
        }
        return ans;
    }
};