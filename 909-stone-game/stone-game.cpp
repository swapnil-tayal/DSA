class Solution {
    vector<vector<vector<int>>> dp;
public:
    
    int f(int i, int j, vector<int> &piles, int isA){

        if(i > j) return 0;
        if(dp[i][j][isA] != -1) return dp[i][j][isA];
        if(isA){
            int left = piles[i] + f(i+1, j, piles, 0);
            int right = piles[j] + f(i, j-1, piles, 0);
            return dp[i][j][isA] = max(left, right);
        }else{
            int left = -piles[i] + f(i+1, j, piles, 1);
            int right = -piles[j] + f(i, j-1, piles, 1);
            return dp[i][j][isA] = min(left, right);
        }
    }
    
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return f(0, n-1, piles, 1) > 0;

    }
};