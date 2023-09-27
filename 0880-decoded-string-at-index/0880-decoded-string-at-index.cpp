class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        long long size = 0;
        int n = s.size();
        
        for(char &i: s){
            if(i >= '0' and i <= '9') size *= (i-'0');
            else size++;
        }
        
        for(int i = s.size()-1; i>=0; i--){
            
            if(s[i] >= 'a' and s[i] <= 'z'){
                if(k == 0 || k == size) return string(1, s[i]);
                size--;
            }
            else{
                size /= (s[i]-'0');
                k %= size;
            }
        }
        return "";
    }
};