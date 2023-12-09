class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++){
            
            if(mp.find(i) != mp.end()) sum -= mp[i];
            nums[i] -= sum;
            if(nums[i] == 0) continue;
            if(nums[i] < 0) return 0;
            
            sum += nums[i];
            mp[i+k] = nums[i];
            nums[i] = 0;
        }
        for(auto i: mp){
            if(i.first > n) return 0;
        }
        return 1;
    }
};