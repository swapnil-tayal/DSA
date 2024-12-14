class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        long long ans = 0;
        int mini = 1e9;
        int maxi = 0;
        map<int,int> mp;
        
        int i = 0;
        int j = 0;
        
        while(j < n){
            
            mp[nums[j]]++;
            if(mp.rbegin()->first - mp.begin()->first <= 2){
                ans += (j-i+1);
                j++;
            
            }else{
                
                while(mp.rbegin()->first - mp.begin()->first > 2){
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                ans += (j-i+1);
                j++;
            }
        }
        return ans;
    }
};