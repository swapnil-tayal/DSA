class Solution {
public:

    int f(int j, int last, vector<string> &strs, vector<vector<int>> &dp){

        if(j == strs[0].size()) return 0;
        if(dp[j][last+1] != -1) return dp[j][last+1];

        int remove = 1 + f(j+1, last, strs, dp);
        int add = 1e9;
        int canAdd = 1;
        if(last != -1){
            for(int i=0; i<strs.size(); i++){
                if(strs[i][last] > strs[i][j]){
                    canAdd = 0;
                    break;
                }
            }
        }
        if(canAdd) add = f(j+1, j, strs, dp);
        return dp[j][last+1] = min(remove, add);
    }

    int minDeletionSize(vector<string>& strs) {
        
        int m = strs[0].size();
        vector<vector<int>> dp(m, vector<int>(m+1, -1));
        return f(0, -1, strs, dp);
    }
};