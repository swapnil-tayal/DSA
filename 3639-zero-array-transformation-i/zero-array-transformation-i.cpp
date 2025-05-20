class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        vector<int> a(nums.size(), 0);
        for(auto i: queries){
            int s = i[0];
            int e = i[1];
            a[s]++;
            if(e+1 < n) a[e+1]--;
        }
        for(int i=1; i<n; i++){
            a[i] = a[i-1] + a[i];
        }
        for(int i=0; i<n; i++){
            if(nums[i] > a[i]){
                return 0;
            }
        }
        return 1;
    }
};