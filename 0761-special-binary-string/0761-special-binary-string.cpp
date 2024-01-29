class Solution {
public:
    
    string f(string &s){
        
        if(s.size() <= 2) return s;
        
        int n = s.size();
        string str = "";
        int cnt = 0;
        vector<string> ans;
        
        for(int i=0; i<n; i++){
            cnt += s[i]=='1';
            cnt -= s[i]=='0';
            str += s[i];
            if(cnt == 0){
                if(str.size() == n){
                    str.erase(0, 1);
                    if(str.size()) str.pop_back();
                }
                // if(s.size() == 8) cout<<str<<' ';
                ans.push_back(f(str));
                str = "";
            }
        }
        sort(ans.rbegin(), ans.rend());
        // for(auto i: ans) cout<<i<<' ';
        // cout<<'\n';
        str = "";
        for(auto i: ans) str += i;
        if(ans.size() == 1){
            str = "1" + str;
            str += "0";
        }
        // cout<<str<<' ';
        return str;
    }
    
    string makeLargestSpecial(string s) {
        
        return f(s);
    }
};