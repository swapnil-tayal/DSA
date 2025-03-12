class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cnt = 0;
        int d = 0;
        for(auto i: nums){
            d += (i==0);
            cnt += (i>0);
        }
        return max((int)nums.size()-d-cnt, cnt);
    }
};