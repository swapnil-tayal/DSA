class Solution{
public:
    int minimumDeletions(string s){
        
        int n = s.size();
        vector<int> cntb(n, 0);
        vector<int> cnta(n, 0);
        
        cntb[0] = s[0] == 'b';
        cnta[n-1] = s[n-1] == 'a';
        
        for(int i=1; i<n; i++){
            cntb[i] = cntb[i-1] + (s[i] == 'b');
        }
        for(int i=n-2; i>=0; i--){
            cnta[i] = cnta[i+1] + (s[i] == 'a');
        }
        // for(auto i: cntb) cout<<i<<' ';
        // cout<<'\n';
        // for(auto i: cnta) cout<<i<<' ';
        // cout<<'\n';
        
        int ans = 1e9;
        for(int i=-1; i<n; i++){
            ans = min(ans, (i>=0 ? cntb[i] : 0) + (i+1 < n ? cnta[i+1] : 0));
        }
        return ans;
    }
};