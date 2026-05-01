class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;

        int arrSum = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += (i * nums[i]);
            arrSum += nums[i];
        }   
        
        ans = sum;
        int lastInd = n-1;

        for(int i=1; i<n; i++){

            int newSum = sum + arrSum - ((n) * nums[lastInd]);
            sum = newSum;
            ans = max(ans, sum);
            lastInd -= 1;

        }
        return ans;
    }
};