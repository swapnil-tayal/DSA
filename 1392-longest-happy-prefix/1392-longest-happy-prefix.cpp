class Solution {
public:
    
    int lpsFind(string needle){
        int n = needle.size();
        vector<int> lps(n, 0);
        
        int prevLps = 0;
        int i = 1;
        while(i < n){
            if(needle[i] == needle[prevLps]){
                lps[i] = prevLps+1;
                i++;
                prevLps++;
            }else{
                if(prevLps == 0){
                    lps[i] = 0;
                    i++;
                }else{
                    prevLps = lps[prevLps-1];
                }
            }
        }
        return lps[n-1];
    }
    
    string longestPrefix(string s) {
        
        int n = lpsFind(s);
        string str = "";
        for(int i=0; i<n; i++) str += s[i];
        return str;
    }
};