class Solution {
    int n;
public:
    
    vector<long long> findPreSuf(vector<int> &a){
        
        vector<int> preSm(n);
        stack<int> st;
        st.push(0);
        
        for(int i=0; i<n; i++){
            
            while(!st.empty() and a[st.top()] >= a[i]) st.pop();
            if(st.empty()) preSm[i] = -1;
            else preSm[i] = st.top();
            st.push(i);
        }
        
        vector<long long> pre(n);
        for(int i=0; i<n; i++){
            
            if(preSm[i] == -1) pre[i] = (long long)a[i]*(long long)(i+1);
            else pre[i] = pre[preSm[i]] + (long long)(i - preSm[i]) * (long long)a[i];
        }
        return pre;
        
        
    }
    
    long long maximumSumOfHeights(vector<int>& a) {
        
        n = a.size();
        vector<long long> pre = findPreSuf(a);
        reverse(a.begin(), a.end());
        vector<long long> suf = findPreSuf(a);
        reverse(suf.begin(), suf.end());
        
        // for(auto i: pre) cout<<i<<' ';
        // cout<<'\n';
        // for(auto j: suf) cout<<j<<' ';
        // cout<<'\n';
        
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, pre[i] + suf[i] - a[n-i-1]);
        }
        return ans;
    }
};