class Solution {
public:
    long long f(int n){
        long long val = 0;
        while(n > 0){
            val += n%10;
            val = val*10;
            n = n/10;    
        }
        return val/10;
    }
    
    int countNicePairs(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int> mp;
        long long ans = 0;
        for(int i=0; i<n; i++){
            // cout<<f(nums[i])<<' ';
            nums[i] = nums[i] - f(nums[i]);
            if(mp.find(nums[i]) != mp.end()){
                ans = (ans + mp[nums[i]]) % (int)(1e9+7);
            }
            mp[nums[i]]++;
        }
        for(auto i: mp){
            // ans += ((long long)i.second*(long long)(i.second-1)/2) % (int)(1e9+7);
        }
        
        return ans;
    }
};