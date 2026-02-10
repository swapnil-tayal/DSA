class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int arr[100001] = {0};
            int cnt = 0;
            for(int j=i; j<n; j++){
                if(arr[nums[j]] == 0) {
                    arr[nums[j]] = 1;
                    if(nums[j] % 2) cnt++;
                    else cnt--;
                }
                if(cnt == 0) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};