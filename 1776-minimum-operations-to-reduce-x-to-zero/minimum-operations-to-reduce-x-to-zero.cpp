class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        map<int,int> mpPre, mpSuf;
        mpPre[0] = 0;
        mpSuf[0] = 0;

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mpPre.count(sum) == 0) mpPre[sum] = i+1;
        }
        if(sum < x) return -1;
        sum = 0;
        for(int i=n-1; i>=0; i--){
            sum += nums[i];
            if(mpSuf.count(sum) == 0) mpSuf[sum] = n-i;
        }
        int ans = 1e9;
        sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int find = x - sum;
            if(find < 0) break;
            if(find == 0) ans = min(ans, i+1);
            if(mpSuf.count(find) and mpSuf[find] >= i){
                ans = min(ans, i+1+mpSuf[find]);
            }
        }        
        sum = 0;
        for(int i=n-1; i>=0; i--){
            sum += nums[i];
            int find = x - sum;
            if(find < 0) break;
            if(find == 0) ans = min(ans, n-i);
            if(mpPre.count(find) and mpPre[find] <= i){
                ans = min(ans, mpPre[find]+n-i);
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};