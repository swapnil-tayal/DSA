class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.size();
        int cnta = 0;
        for(auto &i: s){
            cnta += (i=='a');
        }
        int cntb = 0;
        int ans = n-1;
        ans = min(ans, cntb + cnta);
        for(int i=0; i<n; i++){
            ans = min(ans, cntb + cnta);
            cnta -= (s[i]=='a');
            cntb += (s[i]=='b');
        }
        ans = min(ans, cntb + cnta);
        return ans;
    }
};