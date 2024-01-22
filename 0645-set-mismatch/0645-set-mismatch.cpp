class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        
        map<int, int> mp;
        
        for(int i=0; i<n; i++) mp[nums[i]]++;
        
        int a, b;
        for(int i=1; i<=n; i++){
            if(mp[i] == 0) a = i;
            if(mp[i] == 2) b = i;
        }
        return {b, a};
    }
};