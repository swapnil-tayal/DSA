class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n = nums.size();
        map<int,vector<int>> mp;
        int ans = 1e9;
        int sum = 0;
        for(int i=n-1; i>=0; i--){
            sum += nums[i];
            sum = sum % p;
            mp[sum].push_back(i);
            if(sum % p == 0) ans = min(ans, i);
        }
        for(auto &i: mp){
            reverse(i.second.begin(), i.second.end());
        }
        // for(auto i: mp){
        //     cout<<i.first<<'-';
        //     for(auto j: i.second) cout<<j<<' ';
        //     cout<<'\n';
        // }
        // cout<<'\n';
        sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            sum = sum % p;
            int rem = (p - sum) % p;
            // cout<<rem<<' ';
            if(sum % p == 0) ans = min(ans, n-i-1);
            
            if(mp[rem].size() == 0) continue;
            int ind = upper_bound(mp[rem].begin(), mp[rem].end(), i) - mp[rem].begin();
            // cout<<ind<<'\n';
            if(ind < mp[rem].size()){
                ans = min(ans, mp[rem][ind] - i - 1);
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};