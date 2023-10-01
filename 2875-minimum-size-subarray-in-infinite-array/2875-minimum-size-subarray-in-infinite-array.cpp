class Solution{
public:
    
    int minOperations(vector<int>& nums, int x) {
    
        int n = nums.size();
        vector<long long> pre(n);
        pre[0] = nums[0];
        long long suf = nums[n-1];
        unordered_map<int,int> mp;
        
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        mp[suf] = n-1;
        for(int i=n-2; i>=0; i--){
            suf += nums[i];
            mp[suf] = max(mp[suf], i); 
        }
        
        int ans = 1e9;
        for(int i=-1; i<n; i++){
            
            if(i == -1){
                int diff = x;
                if(mp.find(diff) != mp.end()){
                    if(mp[diff] > i){
                        ans = min(ans, i+1+n-mp[diff]);
                    }
                }
            }
            else if(pre[i] == x) ans = min(ans, i+1);
            else if(pre[i] < x){
                
                int diff = x - pre[i];
                if(mp.find(diff) != mp.end()){
                    if(mp[diff] > i){
                        ans = min(ans, i+1+n-mp[diff]);
                    }
                }   
            }else break;
        }
        int i = 0;
        int j = 0;
        int sum = 0;
        while(j < n){

            sum += nums[j];
            if(sum < x) j++;
            else{

                if(sum == x) ans = min(ans, j-i+1);
                while(sum > x){
                    sum -= nums[i];
                    i++;
                }
                if(sum == x) ans = min(ans, j-i+1);
                j++;
            }
        }
        return ans;
    }
    
    int minSizeSubarray(vector<int>& nums, int target) {
        
        long long sum = 0;
        int n = nums.size();
        for(auto &i: nums) sum += i;
        // cout<<sum<<' ';
        
        int ans = (target/sum)*n;
        // cout<<ans<<' ';
        int k = minOperations(nums, target%sum);
        return (k == 1e9) ? -1 : ans+k;
    }
};