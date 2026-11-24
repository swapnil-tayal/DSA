class Solution {
public:
    int maxLength(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){

            long long pro = 1;
            long long lc = 1;
            long long gcd = 0;
            for(int j=i; j<n; j++){

                pro = pro * nums[j];
                lc = lcm(lc, nums[j]);
                gcd = __gcd(gcd, (long long)nums[j]);
                // cout<<pro<<' '<<lc<<' '<<gcd<<'\n';
                if(pro > 2520) break;
                if(pro == lc * gcd) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};