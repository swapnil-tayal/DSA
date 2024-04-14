class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> nextG(n, 0);
        
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() and nums[st.top()] <= nums[i]){
                st.pop();
            }
            
            if(st.empty()) nextG[i] = n;
            else nextG[i] = st.top();
            st.push(i);
        }
        // for(auto i: nextG) cout<<i<<' ';
        // cout<<'\n';
        
        map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        
        long long ans = 0;
        for(int i=0; i<n; i++){
            
            int ind = nextG[i] - 1;
            int curOcc = lower_bound(mp[nums[i]].begin(), mp[nums[i]].end(), i) - mp[nums[i]].begin();
            int lastOcc = upper_bound(mp[nums[i]].begin(), mp[nums[i]].end(), ind) - mp[nums[i]].begin();
            lastOcc--;
            ans += lastOcc - curOcc + 1;
        }
        return ans;
        
    }
};