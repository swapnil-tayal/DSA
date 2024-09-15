class Solution {
public:
    
    long long f(int i, vector<int> &a, vector<int> &b, int cnt, vector<vector<long long>> &dp){
        
        if(cnt == 4) return 0;
        if(i == b.size()){
            if(cnt == 4) return 0;
            else return -1e9;
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
        
        long long pick = (long long)(a[cnt] * (long long)b[i]) + f(i+1, a, b, cnt+1, dp);
        long long npick = f(i+1, a, b, cnt, dp);
        return dp[i][cnt] = max(pick, npick);
    }
    
    long long maxScore(vector<int>& a, vector<int>& b) {
        
        vector<vector<long long>> dp(b.size(), vector<long long>(4, -1));
        return f(0, a, b, 0, dp);
    }
};