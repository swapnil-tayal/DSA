// credits - https://www.youtube.com/watch?v=w1Zo_r7lgfY

class Solution {
public:
    
    int f(int prefi, int j, int cnt, vector<vector<int>> &reqs, vector<vector<int>> &dp){
        
        if(prefi == 0) return cnt==0;
        
        // removing extra cases
        if(j >= 0 and reqs[j][0] == prefi){
            if(reqs[j][1] != cnt) return 0;
            j--;
        }
        
        if(dp[prefi][cnt] != -1) return dp[prefi][cnt];
        int ans = 0;
        
        // pattern
        for(int k=0; k<=min(prefi, cnt); k++){
            ans = (ans + f(prefi-1, j, cnt-k, reqs, dp)) % int(1e9+7);
        }
        return dp[prefi][cnt] = ans;
    }
    
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        
        vector<vector<int>> dp(n+1, vector<int>(401, -1));
        sort(requirements.begin(), requirements.end());
        return f(n-1, requirements.size()-1, requirements.back()[1], requirements, dp);
    }
};