class Solution {
public:
    int longestConsecutive(vector<int>& d) {
        
        set<int> st (d.begin(), d.end());
        vector<int> nums (st.begin(), st.end());
        
        int n = nums.size();
        if(n == 0) return n;
        int i = 1;
        int ans = 1;
        
        while(i < n){
            
            if(nums[i] == nums[i-1]+1){
                
                int cnt = 1;
                while(i < n and nums[i] == nums[i-1]+1){
                    i++;
                    cnt++;
                }
                ans = max(ans, cnt);
            
            }else i++;
        }
        return ans;
    }
};