class Solution {
public:

    int maxDiff(int num) {
        
        string s = to_string(num);
        char dig1 = '-';
        char dig2 = '-';
        for(int i=0; i<s.size(); i++){
            if(s[i] != '9' and dig1 == '-'){
                dig1 = s[i];
            }
            if(s[i] != '1' && s[i] != '0' and dig2 == '-'){
                dig2 = s[i];
            }
        }
        string s1, s2;
        for(auto i: s){
            if(i == dig1) s1 += '9';
            else s1 += i;
        }
        for(auto i: s){
            if(i == dig2){
                if(s[0] == dig2) s2 += '1';
                else s2 += '0';
            }
            else s2 += i;
        }
        // cout<<s2<<'\n';
        return stoi(s1) - stoi(s2);
        
    }
};