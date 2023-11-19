class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        
        int i = 0;
        int k = nums[0];
        int cnt = 0;
        while(i<n and k==nums[i]){
            cnt++;
            i++;
        }
        int ans = 0;
        while(i < n){
            
            int k = nums[i];
            int temp = 0;
            while(i < n and nums[i] == k){
                temp++;
                i++;
            }
            ans += cnt;
            cnt += temp;
        }
        return ans;
    }
};