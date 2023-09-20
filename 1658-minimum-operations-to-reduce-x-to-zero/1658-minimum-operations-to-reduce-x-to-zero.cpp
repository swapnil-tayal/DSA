class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
    
        int n = nums.size();
        vector<int> pre(n), suf(n);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        map<int,int> mp;
        
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        mp[nums[n-1]] = n-1;
        for(int i=n-2; i>=0; i--){
            suf[i] = suf[i+1] + nums[i];
            mp[suf[i]] = max(mp[suf[i]], i); 
        }
        
        int ans = 1e9;
        for(int i=-1; i<n; i++){
            
            if(i == -1){
                int diff = x;
                if(mp.find(diff) != mp.end()){
                    if(mp[diff] > i){
                        ans = min(ans, i+1+n-mp[diff]);
                        // cout<<i<<' '<<mp[diff]<<' '<<i+1+n-mp[diff]<<'\n';
                        // cout<<i+1+n-mp[diff]<<'\n';
                    }
                }
            }
            else if(pre[i] == x) ans = min(ans, i+1);
            else if(pre[i] < x){
                
                // cout<<i<<' ';
                
                int diff = x - pre[i];
                if(mp.find(diff) != mp.end()){
                    if(mp[diff] > i){
                        ans = min(ans, i+1+n-mp[diff]);
                        // cout<<i<<' '<<mp[diff]<<' '<<i+1+n-mp[diff]<<'\n';
                    }
                }
            
            }else break;
        }
        // cout<<ans<<'\n';
        return ans == 1e9 ? -1 : ans;
    }
};