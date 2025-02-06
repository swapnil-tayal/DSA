class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x = nums[i] * nums[j];
                ans += 8*mp[x];
                mp[x]++;
            }
        }
        return ans;
    }
};