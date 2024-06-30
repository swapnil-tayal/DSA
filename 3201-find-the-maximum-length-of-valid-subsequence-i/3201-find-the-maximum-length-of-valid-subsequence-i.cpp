class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = 0;
        int cnt = 0;
        for(auto i: nums){
            cnt += (i%2 == 1);
        }
        maxi = max(maxi, cnt);
        cnt = 0;
        for(auto i: nums){
            cnt += (i%2 == 0);
        }
        maxi = max(maxi, cnt);
        
        int prev = 0;
        cnt = 0;
        for(auto i: nums){
            if(i%2 == prev){
                prev = 1-prev;
                cnt++;
            }
        }
        maxi = max(maxi, cnt);
        prev = 1;
        cnt = 0;
        for(auto i: nums){
            if(i%2 == prev){
                prev = 1-prev;
                cnt++;
            }
        }
        maxi = max(maxi, cnt);
        return maxi;
    }
};