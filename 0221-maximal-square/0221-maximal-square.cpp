class Solution {
public:
    
    int f(int i, int j, int &ans, vector<vector<char>> &a, vector<vector<int>> &dp){
        
        if(i == a.size() and j == a[0].size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = 0, down = 0, diagonal = 0;
        
        if(j+1 < a[0].size()) right = f(i, j+1, ans, a, dp);
        if(i+1 < a.size()) down = f(i+1, j, ans, a, dp);
        if(i+1 < a.size() and j+1 < a[0].size()) diagonal = f(i+1, j+1, ans, a, dp);
        
        if(a[i][j] == '1'){
            
            int k = 1 + min({ right, down, diagonal });
            ans = max(k, ans);
            return dp[i][j] = k;
            
        }return dp[i][j] = 0;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n == 1 and m == 1 and matrix[0][0] == '1') return 1;
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        f(0, 0, ans, matrix, dp); 
        return ans*ans;
    }
};