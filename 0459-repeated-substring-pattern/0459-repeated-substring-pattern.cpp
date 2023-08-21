class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n = s.size();
        string str;
        
        for(int i=0; i<n; i++){
            
            str += s[i];
            if(n % str.size() == 0 and n != str.size()){
                
                int k = n/str.size();
                string temp;
                while(k--){
                    temp += str;
                }
                if(temp == s) return 1;
            }
        }
        return 0;
    }
};