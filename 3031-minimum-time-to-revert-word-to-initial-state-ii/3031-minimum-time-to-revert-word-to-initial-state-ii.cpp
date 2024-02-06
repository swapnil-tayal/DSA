//https://www.youtube.com/watch?v=XbZoVoouBRU&list=WL&index=4

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
    int minimumTimeToInitialState(string word, int k) {
        
        int n = word.size();
        vector<int> lps = lpsFind(word);
        int maxLps = lps[n-1];
        
        int ans = (n+k-1)/k;
        if((n - maxLps)%k == 0){
            ans = min(ans, (n-maxLps)/k);
        }
        while((n - maxLps)%k != 0){
            if(maxLps == 0) break;
            maxLps = lps[maxLps-1];
        }
        if((n - maxLps)%k == 0){
            ans = min(ans, (n-maxLps)/k);
        }
        return ans;
    }
};