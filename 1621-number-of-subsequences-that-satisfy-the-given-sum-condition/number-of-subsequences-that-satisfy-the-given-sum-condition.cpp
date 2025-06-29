class Solution {
    vector<int> pow;
    int mod = (1e9+7);
public:
    Solution(){
        int x = 1;
        for(int i=0; i<100001; i++){
            pow.push_back(x);
            x = (x*2) % mod;
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans  = 0;

        for(int i=0; i<n; i++){
            int x = target - nums[i];
            if(x < nums[i]) continue;
            int ind = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
            ans = (ans + pow[ind-1-i]) % mod;
        }
        return ans;
    }
};