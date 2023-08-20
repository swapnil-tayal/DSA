bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[0] < v2[0];
}

class Solution{
    
    vector<int> str;
public:
    
    int f(int i, vector<vector<int>> &offers, vector<int> &dp){
        
        if(i >= offers.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        int npick = f(i+1, offers, dp);
        
        int ind = upper_bound(str.begin(), str.end(), offers[i][1]) - str.begin();
        int pick = offers[i][2] + f(ind, offers, dp);
        
        return dp[i] = max(pick, npick);
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        
        sort(offers.begin(), offers.end(), cmp);
        
        for(auto i: offers) str.push_back(i[0]);
        
        vector<int> dp(offers.size(), -1);
        return f(0, offers, dp);
    }
};