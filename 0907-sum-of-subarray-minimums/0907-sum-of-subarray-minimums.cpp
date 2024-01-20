class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        const int mod = 1e9+7;
        
        int n = arr.size();
        vector<int> preSm(n, -1), sufSm(n, n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() and arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()) preSm[i] = st.top();
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()) sufSm[i] = st.top();
            st.push(i);
        }
        // for(auto i: preSm) cout<<i<<' ';
        // cout<<'\n';
        // for(auto i: sufSm) cout<<i<<' ';
        // cout<<'\n';
        long long ans = 0;
        int g = 0;
        
        for(int i=0; i<n; i++){
            
            int leftLen = i - preSm[i] - 1;
            int rightLen = sufSm[i] - i - 1;
            
            long long cnt = leftLen + rightLen + (leftLen * rightLen) + 1;
            // g += cnt;
            // cout<<cnt<<' ';
            ans = (ans + (long long)(cnt * (long long)arr[i]) % mod) % mod;
            
            // cout<<leftLen<<' '<<rightLen<<'-';
            // int cnt = sufSm[i] - preSm[i] - 1;
            
        }
        // cout<<'\n';
        // cout<<g<<' '<<n*(n+1)/2<<'\n';
        return ans;
    }
};