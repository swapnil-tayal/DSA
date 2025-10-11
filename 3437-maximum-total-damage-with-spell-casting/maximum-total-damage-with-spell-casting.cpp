class Solution {
    map<int, int> mp;
public:

    long long f(int i, vector<int> &a, vector<long long> &dp){
        if(i == a.size()) return 0;
        if(dp[i] != -1) return dp[i];
        long long npick = f(i+1, a, dp);
        int ind = lower_bound(a.begin(), a.end(), a[i]+3) - a.begin();
        long long pick = ((long long)mp[a[i]] * (long long)a[i]) + f(ind, a, dp);
        return dp[i] = max(pick, npick);
    }

    long long maximumTotalDamage(vector<int>& power) {
        
        sort(power.begin(), power.end());
        int n = power.size();
        for(auto &i: power) mp[i]++;
        
        power.erase(unique(power.begin(), power.end()), power.end());
        vector<long long> dp(n, -1);
        return f(0, power, dp);
    }
};