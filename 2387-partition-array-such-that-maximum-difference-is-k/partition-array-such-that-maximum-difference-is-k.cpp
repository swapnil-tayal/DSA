class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        int prev = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] - prev > k){
                cnt++;
                prev = nums[i];
            }
        }
        return cnt + 1;
    }
};