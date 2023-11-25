class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pre(n, 0), suf(n, 0);
        pre[0] = nums[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        suf[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suf[i] = suf[i+1] + nums[i];
        }
        
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int val = ((i+1)*nums[i]) - pre[i];
            val = val + suf[i] - ((n-i)*nums[i]);
            ans[i] = val;
        }
        return ans;
    }
};