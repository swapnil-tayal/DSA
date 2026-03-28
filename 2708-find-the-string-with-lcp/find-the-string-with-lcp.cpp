class Solution {
public:

    bool verifyLcp(string &s, vector<vector<int>> &lcp){

        int n = s.size();
        vector<vector<int>> a(n, vector<int>(n, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(s[i] == s[j]){

                    if(i+1 < n and j+1 < n) a[i][j] = 1 + a[i+1][j+1];
                    else a[i][j] = 1;   

                }else{
                    a[i][j] = 0;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] != lcp[i][j]) return 0;
            }
        }
        return 1;
    }

    string findTheString(vector<vector<int>>& lcp) {

        int n = lcp.size();
        vector<char> ans(n, '-');
        char ch = 'a';

        for(int i=0; i<n; i++){
            
            if(ans[i] == '-'){
                ans[i] = ch++;
                if(!(ans[i] >= 'a' and ans[i] <= 'z')) return "";
            }
            for(int j=i+1; j<n; j++){
                if(lcp[i][j] > 0){
                    ans[j] = ans[i];
                }
            }
            // char alreadyCh = '-';
            // for(auto k: st){
            //     if(ans[k] != '-') alreadyCh = ans[k];
            // }
            // char newCh = alreadyCh == '-' ? ch++ : alreadyCh;
            // if(!(newCh >= 'a' and newCh <= 'z')) return "";
            // for(auto k: st){
            //     ans[k] = newCh;
            // }
        }
        string res = "";
        for(auto i: ans) res += i;
        if(verifyLcp(res, lcp) == false) return ""; 
        return res;
    }
};