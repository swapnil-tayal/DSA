class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        unordered_map<long long, set<int>> mp;
        int n = nums.size();

        for(int i=0; i<n; i++){
            mp[nums[i]].insert(i);
        }
        set<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){

                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k];
                    long long req = (long long)target - sum;
                    // cout<<sum<<' '<<req<<'\n';

                    if(mp.count(req)){

                         int cnt = mp[req].count(i) != 0;
                         cnt += mp[req].count(j) != 0;
                         cnt += mp[req].count(k) != 0;
                         if(mp[req].size() == cnt) continue;

                        vector<int> temp = {nums[i], nums[j], nums[k], (int)req};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};