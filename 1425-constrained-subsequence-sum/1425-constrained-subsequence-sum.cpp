class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> dp(n, 0);
        priority_queue<pair<int,int>> pq;
        
        pq.push({ nums[0], 0 });
        dp[0] = nums[0];
        int ans = dp[0];
        
        for(int i=1; i<n; i++){
            
            int prev = i-k-1;
            while(pq.top().second <= prev) pq.pop();
            
            dp[i] = max(nums[i], nums[i] + pq.top().first);
            ans = max(ans, dp[i]);
            pq.push({ dp[i], i });
        }
        // for(auto i: dp) cout<<i<<' ';
        return ans;
    }
};