class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> preMx(n, 0);
        vector<int> diff(n, 0);
        vector<int> maxDiff(n, 0);
        
        int mxi = nums[0];
        preMx[0] = -1;
        for(int i=1; i<n; i++){
            preMx[i] = max(mxi, preMx[i-1]);
            mxi = max(mxi, nums[i]);
        }
        // for(auto i: preMx) cout<<i<<' ';
        // cout<<'\n';
        for(int i=1; i<n; i++){
            diff[i] = preMx[i] - nums[i];
        }
        // for(auto i: diff) cout<<i<<' ';
        // cout<<'\n';

        mxi = diff[0];
        maxDiff[0] = -1;
        for(int i=1; i<n; i++){
            maxDiff[i] = max(mxi, maxDiff[i-1]);
            mxi = max(mxi, diff[i]);
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, (long long)maxDiff[i]*(long long)nums[i]);
        }   
        return ans;
        
    }
};