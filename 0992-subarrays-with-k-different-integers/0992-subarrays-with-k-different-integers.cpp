class Solution {
public:
    
    int atMost(int k, vector<int> &nums){
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int,int> mp;
        int cnt = 0;
        
        while(j < n){
            
            mp[nums[j]]++;
            if(mp.size() <= k){
                cnt += (j-i+1);
                j++;
            }else{
                
                while(i < n and mp.size() > k){
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0) mp.erase(nums[i]);
                    i++;
                }
                if(mp.size() <= k) cnt += (j-i+1);
                j++;
            }
        }
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atMost(k, nums) - atMost(k-1, nums);
    }
};