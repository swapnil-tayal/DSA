class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size();
        vector<int> a(n, 0);

        for(auto &i: shifts){
            int ch = (i[1]+1 < n);
            if(i[2] == 1){
                a[i[0]]++;
                if(ch) a[i[1]+1]--;
            }
            else{
                a[i[0]]--;
                if(ch) a[i[1]+1]++;
            }
        }

        // for(auto i: a) cout<<i<<' ';
        // cout<<'\n';

        for(int i=1; i<n; i++) a[i] += a[i-1];
        
        // for(auto i: a) cout<<i<<' ';
        // cout<<'\n';

        for(int i=0; i<n; i++){
            int ind = s[i]-'a';
            a[i] += ind;
            a[i] = a[i]<0 ? -(abs(a[i]) % 26) : a[i]%26;
            ind = a[i];
            // cout<<ind<<' ';
            if(ind >= 0) s[i] = char(ind+'a');
            else{
                ind = 26 + ind;
                s[i] = char(ind+'a');
            }
        }
        return s;
    }
};