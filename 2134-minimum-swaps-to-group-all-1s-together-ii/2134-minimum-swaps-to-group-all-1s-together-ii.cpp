class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int cnt = 0;
        for(auto i: nums) cnt += (i==1);
        
        int i = 0;
        int j = 0;
        int n = nums.size();
        
        vector<int> a(nums.begin(), nums.end());
        for(auto &i: nums) a.push_back(i);
        n = a.size();
        
        int tillOne = 0;
        int ans = cnt;
        
        while(j < n){
            
            tillOne += (a[j] == 1);
            if(j-i+1 < cnt) j++;
            else{
                
                ans = min(ans, cnt - tillOne);
                tillOne -= (a[i]==1);
                i++;
                j++;
            }
        }
        return ans;
    }
};