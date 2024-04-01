class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        
        for(int i=s.length()-1; i>=0; i--){
            
            if(ans > 0 && s[i]==' '){
                return ans;
            }
            if(s[i]!=' '){
                ans++;
            }
        }
        return ans;
    }
};