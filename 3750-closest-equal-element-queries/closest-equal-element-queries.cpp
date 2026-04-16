class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> a;
        for(auto &i: queries){

            if(mp.find(nums[i]) == mp.end()){
                a.push_back(i);
                break;
            }
            int ind = lower_bound(mp[nums[i]].begin(), mp[nums[i]].end(), i) - mp[nums[i]].begin();
            int sz = mp[nums[i]].size();
            int prev = mp[nums[i]][(ind - 1 + sz) % sz];
            int next = mp[nums[i]][(ind + 1) % sz];
            int curr = mp[nums[i]][ind];

            int res = 1e9;
            
            if(ind == 0) res = min(res, curr + n - prev);
            else res = min(res, abs(curr - prev));

            if(ind == sz-1) res = min(res, n - curr + next);
            else res = min(res, abs(next - curr));

            if(res == n) res = -1;
            a.push_back(res);
        }
        return a;
    }
};
