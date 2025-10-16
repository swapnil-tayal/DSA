class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                int x = (value - (abs(nums[i]) % value)) % value;
                mp[x]++;
            }else{
                mp[nums[i] % value]++;
            }
        }
        for(int i=0; i<=100000; i++){
            int x = i%value;
            if(mp[x] > 0) mp[x]--;
            else return i;
        }
        return -1;
    }
};