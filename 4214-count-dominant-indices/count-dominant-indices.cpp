class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        
        int ans = 0;
        int n = nums.size();
        int sum = nums[n-1];
        int cnt = 1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] > (sum / cnt)){
                ans++;
            }
            cnt++;
            sum += nums[i];
        }
        return ans;
    }
};