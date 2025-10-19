class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        cout<<s.size();
        string e, o;
        for(int i=0; i<s.size(); i++){
            if(i%2 == 0) e += s[i];
            else o += s[i];
        }
        vector<string> ve, vo;
        ve.push_back(e);
        vo.push_back(o);
        for(int k=1; k<10; k++){
            string str;
            for(auto &i: o){
                str += char(((i-'0') + k*a)%10 + '0');
            }
            vo.push_back(str);
            if(b%2){
                string str;
                for(auto &i: e){
                    str += char(((i-'0') + k*a)%10 + '0');
                }
                ve.push_back(str);
            }
        }
        string res(100, '9');
        for(auto s1: vo){
            for(auto s2: ve){
                string str = "";
                int i = 0;
                int j = 0;
                // cout<<s1<<' '<<s2<<' ';
                for(int k=0; k<s.size()/2; k++){
                    str += s2[k];
                    str += s1[k];
                }
                // cout<<str<<'\n';
                for(int k=0; k<s.size(); k++){
                    // cout<<str<<'\n';
                    rotate(str.rbegin(), str.rbegin() + b, str.rend());
                    res = min(res, str);
                }
                // cout<<'\n';
            }
        }
        return res;
    }
};