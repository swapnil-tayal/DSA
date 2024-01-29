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
                
                str.erase(0, 1);
                str.pop_back();
                
                ans.push_back("1" + f(str) + "0");
                str = "";
            }
        }
        sort(ans.rbegin(), ans.rend());
        
        str = "";
        for(auto i: ans) str += i;
        return str;
    }
    
    string makeLargestSpecial(string s) {
        
        return f(s);
    }
};