class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        long long n = nums.size();
        if(n == 1) return 0;
        
        vector<long long> pre(n);
        pre[0] = nums[0];
        
        for(long long i=1; i<n; i++){
            pre[i] += pre[i-1] + nums[i];
        }
        
        map<long long,long long> mp;
        mp[0] = -1;
        long long sum = 0;
        
        for(long long i=0; i<n; i++){
            
            sum += nums[i];
            sum = sum % k;
            if(mp.find(sum) != mp.end()){
                
                long long sumCur = pre[i];
                // cout<<i<<' '<<mp[sum]<<'\n';
                
                if(mp[sum] != -1){
                    
                    if(i-mp[sum] < 2) continue; 
                    sumCur -= pre[mp[sum]];
                
                }else if(i < 1) continue;
                
                // cout<<sum<<'\n';
                if(sumCur % k == 0) return 1;
            }
            mp[sum] = i;
        }
        return 0;
    }
};