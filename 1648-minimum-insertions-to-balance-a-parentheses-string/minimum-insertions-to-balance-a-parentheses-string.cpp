class Solution {
public:
    int minInsertions(string s) {
        
        string str = "";
        int ind = 0;
        int n = s.size();
        int ans = 0;

        while(ind < n){

            char ch = s[ind];
            int cnt = 0;
            while(ind < n and s[ind] == ch){
                cnt++;
                ind++;
            }
            if(ch == '('){
                while(cnt--) str += '(';
            }
            else{
                if(cnt%2 == 1){
                    cnt++;
                    ans++;
                }
                cnt = cnt/2;
                while(cnt--) str += ')';
            }
        }
        stack<char> st;
        int o = 0;
        int c = 0;
        for(auto &i: str){

            if(i == '(') o++;
            else c++;
            if(i == ')' and o < c){
                ans += c-o;
                c = 0;
                o = 0;
            }
        }
        ans += 2*abs(o-c);
        return ans;
    }
};