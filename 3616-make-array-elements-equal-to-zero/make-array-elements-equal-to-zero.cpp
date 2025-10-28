class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        
        int tot = 0;
        for(auto i: nums) tot += i;
        int c = 0;
        int ans = 0;
        for(auto &i: nums){
            c += i;
            if(i == 0 and c == tot-c) ans += 2;
            if(i == 0 and abs(tot - 2*c) == 1) ans++;            
        }
        return ans;
    }
};