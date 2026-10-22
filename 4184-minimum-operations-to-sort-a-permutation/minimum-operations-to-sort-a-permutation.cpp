class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        int ind = min_element(nums.begin(), nums.end()) - nums.begin();
        if(n == 1) return 0;

        int dir = nums[(ind+1)%n] == 1 ? 1 : -1;
        if(dir == 1){

            int prev = 0;
            int i = ind+1;
            while(i < ind+n){
                if(nums[i % n] != prev+1) return -1;
                prev = nums[i % n];
                i = i+1;
            }
        }else{
            int prev = 0;
            int i = ind-1;
            while(i > ind-n){
                if(nums[(i % n + n) % n] != prev+1) return -1;
                prev = nums[(i % n + n) % n];
                i = i-1;
            }
        }
        if (dir == 1) return min(ind, n - ind + 2);
        else return min((ind + 1) % n + 1, n - ind);
    }
};