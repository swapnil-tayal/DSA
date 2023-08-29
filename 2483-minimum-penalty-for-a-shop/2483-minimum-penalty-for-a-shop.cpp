class Solution {
public:
    int bestClosingTime(string a) {
        
        int n = a.size();
        int ans = 1e9;
        
        vector<int> pre(n+1, 0);
        vector<int> suf(n+1, 0);
        
        pre[0] = (a[0] == 'N');
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + (a[i]=='N');
        }
        suf[n-1] = (a[n-1] == 'Y');
        for(int i=n-2; i>=0; i--){
           suf[i] = suf[i+1] + (a[i]=='Y');  
        }
        
        pre[n] = pre[n-1];

        // for(auto i: pre) cout<<i<<' ';
        // cout<<'\n';
        // for(auto j: suf) cout<<j<<' ';
        // cout<<'\n';
        
        int ind = 0;
        for(int i=0; i<=n; i++){
            
            int x = suf[i];
            if(i > 0) x += pre[i-1];
            if(ans > x){
                ans = x;
                ind = i;
            }
        }
        return ind;
    }
};