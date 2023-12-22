class Solution {
public:
    
    vector<int> lpsFind(string needle){
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
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        
        if(needle.size() == 0) return -1;
        vector<int> lps = lpsFind(needle);
        
        int i = 0; // haystack
        int j = 0; // needle
        
        while(i < haystack.size()){
            
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }else{
                if(j == 0){
                    i++;
                }else{
                    j = lps[j-1];
                }
            }
            if(j == needle.size()) return i-needle.size();
        }
        return -1;
    }
};