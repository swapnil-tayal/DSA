class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        int cnt = 0;
        
        for(int k=0; k<n; k++){
            
            int i = k;
            int j = k;
            while(i >= 0 and j < n){
                if(s[i] != s[j]) break;
                i--; j++; cnt++;
            }
        }
        for(int k=0; k<n-1; k++){
            
            int i = k;
            int j = k+1;
            while(i >= 0 and j < n){
                if(s[i] != s[j]) break;
                i--; j++; cnt++;
            }
        }
        return cnt;
    }
};