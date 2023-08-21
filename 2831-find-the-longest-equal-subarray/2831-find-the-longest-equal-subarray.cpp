class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        map<int,vector<int>> mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        
        int ans = 0;
        for(auto g: mp){
            
            vector<int> a {g.second.begin(), g.second.end()};
            int cnt = 0;
            
            if(a.size() == 1){
                ans = max(ans, 1);
                continue;
            }
            
            int i = 1;
            int j = 1;
            int tempK = k;
            
            while(j < a.size()){
                
                tempK -= (a[j] - a[j-1]-1);
                if(tempK >= 0) cnt = max(cnt, a[j] - a[i-1] + 1 - (k - tempK));
                else{
                    
                    while(i < a.size() and tempK < 0){
                        
                        tempK += (a[i] - a[i-1]-1);
                        i++;
                    }
                    if(tempK >= 0) cnt = max(cnt, a[j] - a[i-1] + 1 - (k - tempK));
                }j++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};