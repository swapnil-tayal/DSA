class Solution {
public:

    int f(int i, vector<vector<int>> &events, vector<int> &start, int k, vector<vector<int>> &dp){

        if(i == events.size() || k == 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int npick = f(i+1, events, start, k, dp);
        int ind = upper_bound(start.begin()+i+1, start.end(), events[i][1]) - start.begin();
        int pick = events[i][2] + f(ind, events, start, k-1, dp);
        return dp[i][k] = max(pick, npick);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        
        sort(events.begin(), events.end());
        vector<int> start;
        for(auto i: events) start.push_back(i[0]);
        vector<vector<int>> dp(events.size(), vector<int>(k+1, -1));
        return f(0, events, start, k, dp);
    }
};