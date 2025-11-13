class Solution {
public:
    int maxOperations(string s) {
        
        int ans = 0;
        int zeros = 0;

        string str = "";
        int i = 0;
        while(i < s.size()){
            if(s[i] == '1'){
                str += s[i];
                i++;
            }else{
                while(i < s.size() && s[i] == '0') i++;
                str += "0";
            }
        }
        for(int i=str.size()-1; i>=0; i--){
            if(str[i] == '0') zeros++;
            else ans += zeros;
        }
        return ans;
    }
};