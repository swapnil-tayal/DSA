class Solution {
    map<long long,long long> mp;
    map<long long,long long> mp2;
    int n;
public:
    
    
    long long maximumTotalDamage(vector<int>& power) {
        
        set<int> st;
        for(auto &i: power){
            mp[i]++;
            st.insert(i);
        }
        vector<int> arr(st.begin(), st.end());
        n = arr.size();
        
        for(int i=0; i<n; i++){
            mp2[i] = lower_bound(arr.begin(), arr.end(), arr[i]+3) - arr.begin();
        }
        
        vector<long long> dp(n+1, 0);
        
        for(int i=n-1; i>=0; i--){
            long long npick = 0;
            long long pick = 0;

            npick = dp[i+1];
            pick = (mp[arr[i]] * arr[i]) + dp[mp2[i]];
            dp[i] = max(npick, pick);
        }
        
        return dp[0];
    }
};