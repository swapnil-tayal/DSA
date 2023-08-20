class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();
        
        if(str2.size() > str1.size()) return 0;
        
        int j = 0;
        for(int i=0; i<n; i++){
            
            char nextChar = char(str1[i]+1);
            if(str1[i] == 'z') nextChar = 'a';
            
            if(str2[j] == str1[i] || str2[j] == nextChar) j++;
            
            if(j == m) return 1;
        }
        return 0;
    }
};