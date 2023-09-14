class Solution {
    const int mod = 1e9 + 7;
public:
    int waysToSplit(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for(int i=1; i<n; i++) pre[i] = pre[i-1] + nums[i];

        int cnt = 0;
        for(int i=0; i<n-2; i++){
            
            int k = 2*pre[i];
            int ind1 = lower_bound(pre.begin(), pre.end(), k) - pre.begin();
            if(ind1 <= i) ind1 = i+1;
            
            k = (pre[i] + pre[n-1])/2;
            int ind2 = upper_bound(pre.begin(), pre.end(), k) - pre.begin() - 1;
            if(ind2 >= n-1) ind2 = n - 2;
            
            // cout<<i<<' '<<ind1<<' '<<ind2<<'\n';
            
            if(i < ind1 and ind1 <= ind2)
            // if(pre[i] <= pre[ind1]-pre[i] and pre[n-1]-pre[ind2] >= pre[ind2]-pre[i])
            cnt = (cnt + ind2 - ind1 + 1) % mod;
        }
        return cnt;
    } 
};