class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = 0;
        vector<int> a(n+1, 0);
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++){
            
            sum -= a[i];
            nums[i] -= sum;
            if(nums[i] == 0) continue;
            if(nums[i] < 0) return 0;
            
            sum += nums[i];
            if(i+k > n) return 0;
            a[i+k] = nums[i];
            nums[i] = 0;
        }
        return 1;
    }
};