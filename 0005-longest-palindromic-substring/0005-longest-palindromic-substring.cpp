class Solution {
public:
    string longestPalindrome(string str) {
        
        int n = str.size();
        int maxL = 0;
        int maxR = 0;
        
        for(int k=0; k<n; k++){
            
            int i = k-1;
            int j = k+1;
            int s = k;
            int e = k;
            
            while(i >= 0 and j < n){
                if(str[i] == str[j]){
                    s--;
                    e++;
                    i--; j++;
                }else break;
            }
            if(e-s+1 > maxR-maxL+1){
                maxR = e; maxL = s;
            }
            
            i = k;
            j = k+1;
            s = k;
            e = k;
            
            while(i >= 0 and j < n){
                if(str[i] == str[j]){
                    s--;
                    e++;
                    i--; j++;
                }else break;
            }
            if(e-s+1 > maxR-maxL+1){
                maxR = e; maxL = s+1;
            }
        }
        
        string s;
        for(int i=maxL; i<=maxR; i++) s += str[i];
        
        return s;
    }
};