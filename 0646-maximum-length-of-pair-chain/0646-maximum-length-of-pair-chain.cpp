class Solution {
    
    vector<int> str;
public:
    
    int f(int i, vector<vector<int>> &pairs, vector<int> &dp){
        
        if(i >= pairs.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        int npick = f(i+1, pairs, dp);
        
        int ind = upper_bound(str.begin(), str.end(), pairs[i][1]) - str.begin();
        int pick = 1 + f(ind, pairs, dp);
        return dp[i] = max(pick, npick);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        for(auto i: pairs) str.push_back(i[0]);
        vector<int> dp(n, -1);
        return f(0, pairs, dp);
        
    }
};