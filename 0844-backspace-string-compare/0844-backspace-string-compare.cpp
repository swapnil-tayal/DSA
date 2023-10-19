class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string str1, str2;
        for(auto i: s){
            if(i == '#' and str1.size()) str1.pop_back();
            else if(i != '#') str1 += i;
        }
        for(auto i: t){
            if(i == '#' and str2.size()) str2.pop_back();
            else if(i != '#') str2 += i;
        }
        return str1 == str2;
    }
};