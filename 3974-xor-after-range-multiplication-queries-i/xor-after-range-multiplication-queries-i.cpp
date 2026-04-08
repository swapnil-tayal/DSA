class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        for(auto &i: queries){
            for(int k=i[0]; k<=i[1]; k+=i[2]){
                nums[k] = (long long)(nums[k] * (long long)i[3]) % int(1e9+7);
            }
        }
        int ans = 0;
        for(auto i: nums) ans = ans ^ i;
        return ans; 
    }
};