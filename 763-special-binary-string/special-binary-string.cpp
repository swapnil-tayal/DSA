class Solution {
public:

    string f(string s){

        if(s.size() <= 2) return s;
        int cnt = 0;
        vector<string> a;
        string str = "";
        for(int i=0; i<s.size(); i++){

            if(s[i] == '1') cnt++;
            else cnt--;
            str += s[i];

            if(cnt == 0){
                string temp = "1";
                temp += f(str.substr(1, str.size()-2));
                temp += "0"; 
                a.push_back(temp);
                str = "";
            }
        }
        string res = "";
        sort(a.rbegin(), a.rend());
        for(auto &i: a) res += i;
        return res;
    }

    string makeLargestSpecial(string s) {
        return f(s);
    }
};