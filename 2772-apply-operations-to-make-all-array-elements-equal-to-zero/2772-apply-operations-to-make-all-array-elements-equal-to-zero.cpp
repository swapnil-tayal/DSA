class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        // for(int i=1; i<n; i++){
        //     pre[i] = pre[i-1] + nums[i];
        // }
        
        // 1 4 5 6
        
        int sum = 0;
        map<int,int> mp;
        
        for(int i=0; i<n; i++){
            
            if(mp.find(i) != mp.end()) sum -= mp[i];
            nums[i] -= sum;
            // cout<<nums[i]<<' ';
            if(nums[i] == 0) continue;
            if(nums[i] < 0) return 0;
            
            sum += nums[i];
            mp[i+k] = nums[i];
            nums[i] = 0;
        }
        
        for(auto i: mp){
            if(i.first > n) return 0;
        }
        
        // cout<<'\n';
        // for(auto i: nums) cout<<i<<' ';
        // cout<<'\n';
        return 1;
    }
};