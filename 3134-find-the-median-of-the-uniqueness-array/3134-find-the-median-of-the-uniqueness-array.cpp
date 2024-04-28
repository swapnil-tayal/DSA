class Solution {
public:
    
    long long atMost(vector<int> &nums, int k){
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int,int> mp;
        long long cnt = 0;
        
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
    
    int medianOfUniquenessArray(vector<int>& nums) {
        
        int n = nums.size();
        int s = 1;
        int e = n;
        long long total = (long)n*(n+1)/2;
        int ans = 1e9;
        
        while(s <= e){
            
            int mid = (s+e)/2;
            
            // atmost(k) >= total - atmost(k);
            if(2 * (long)atMost(nums, mid) >= total){
                ans = mid;
                e = mid-1;
                
            }else s = mid+1;
        }
        return ans;
    }
};