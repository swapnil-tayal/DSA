class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        int xr = 0;
        int xr2 = 0;
        for(auto &i: nums){
            xr ^= i;
            xr2 ^= (i+1); 
        }
        return xr == 0 && xr2 == 0;
    }
};