class Solution {
public:

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int i = 1;
        vector<int> a;
        int cnt = 1;
        while(i < nums.size()){
            if(nums[i] <= nums[i-1]){
                a.push_back(cnt);
                cnt = 1;
            }else cnt++;
            i++;
        }        
        a.push_back(cnt);
        for(int i=0; i<a.size(); i++){
            if(a[i] >= 2*k) return 1;
            if(i > 0 and a[i] >= k and a[i-1] >= k) return 1;
        }
        return 0;
    }
};