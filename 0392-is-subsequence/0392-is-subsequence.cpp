class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int j = 0;
        for(int i=0; i<t.size(); i++){
            
            if(t[i] == s[j]) j++;
            if(j == s.size()) return 1;
        }
        if(j == s.size()) return 1;
        return 0;
    }
};