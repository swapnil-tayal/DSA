class Solution {
public:
    
    void f(vector<int> &nums, vector<int> &arr, int f){
        
        int n = nums.size();
        stack<pair<int,int>> st;
        for(int i=0; i<n; i++){
            
            if(st.empty()){
             
                if(f) st.push({ nums[i], n-i-1 });
                else st.push({ nums[i], i });
            
            }else{
                
                while(!st.empty() and st.top().first >= nums[i]){
                    st.pop();
                }
                if(!st.empty()) arr[i] = st.top().second;
                if(f) st.push({ nums[i], n-i-1 });
                else st.push({ nums[i], i });
            }
        }
    }
    
    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        
        f(nums, left, 0);
        reverse(nums.begin(), nums.end());
        f(nums, right, 1);
        reverse(nums.begin(), nums.end());
        reverse(right.begin(), right.end());
        
        // for(auto i: left) cout<<i<<' ';
        // cout<<'\n';
        // for(auto i: right) cout<<i<<' ';
        // cout<<'\n';
        
        int ans = 0;
        for(int i=0; i<n; i++){
            
            int l = left[i];
            int r = right[i];
            // cout<<l<<' '<<r<<'\n';
            if(l+1 <= k and r-1 >= k){
                
                int sm = nums[i]*(r-l-1);
                ans = max(ans, sm);
            }
        }
        
        return ans;
    }
};