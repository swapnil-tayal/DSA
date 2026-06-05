class Solution {
    int b = -1;
    unordered_map<string, long long> dp;
public:

    long long f(int ind, string s, string e, int prev1, int prev2, int upDown, int cnt, int lz2){

        if(ind == s.size()){
            return cnt;
        }
        string r = to_string(ind) + '-' + to_string(prev1) + '-' + to_string(prev2) + '-' + to_string(upDown) + '-' + to_string(cnt) + '-' + to_string(lz2);

        if(dp.count(r)) return dp[r];
        long long ans = 0;
        if(prev2 == -1){
            for(char ch='0'; ch<='9'; ch++){
                int nlz2 = (ch == '0' and s[ind] == '0');
                if(ch >= s[ind] and ch <= e[ind]){
                    int x = (ch==s[ind] and ch==e[ind]) ? 2 :  ch == s[ind] ? 0 : (ch == e[ind] ? 1 : -1);
                    ans += f(ind+1, s, e, prev1, ch - '0', x, cnt, nlz2);

                }
            }
        }
        else if(prev1 == -1){

            // cout<<prev2<<' '<<upDown<<'\n';

            for(char ch='0'; ch<='9'; ch++){
                int curr = ch - '0';

                if(upDown == -1){
                    ans += f(ind+1, s, e, curr, prev2, upDown, cnt, lz2);
                
                } else if(upDown == 0 && ch >= s[ind]){
                    int x = ch == s[ind] ? 0 : -1;
                    ans += f(ind+1, s, e, curr, prev2, x, cnt, lz2);
                
                } else if(upDown == 1 && ch <= e[ind]){
                    int x = ch == e[ind] ? 1 : -1;
                    ans += f(ind+1, s, e, curr, prev2, x, cnt, lz2);

                } else if(upDown == 2 && ch >= s[ind] and ch <= e[ind]){
                    int x = (ch==s[ind] and ch==e[ind]) ? 2 :  ch == s[ind] ? 0 : (ch == e[ind] ? 1 : -1);
                    ans += f(ind+1, s, e, curr, prev2, x, cnt, lz2);
                }
            }
        }
        else {

            // cout<<prev2<<' '<<prev1<<' '<<upDown<<' '<<lz2<<'\n';

            for(char ch='0'; ch<='9'; ch++){
                int curr = ch - '0';
                int nlz2 = (prev1 == 0 and s[ind-1] == '0') && lz2;
                int inc = (prev1 > prev2 and prev1 > curr) || (prev1 < prev2 and prev1 < curr) ? 1 : 0;
                if(lz2) inc = 0;

                // cout<<prev2<<' '<<prev1<<' '<<ch<<' '<<nlz<<'\n';

                if(upDown == -1){
                    // if(inc == 1) cout<<prev2<<' '<<prev1<<' '<<' '<<curr<<' '<<upDown<<'\n';
                    ans += f(ind+1, s, e, curr, prev1, upDown, cnt + inc, nlz2);
                    
                } else if(upDown == 0 and ch >= s[ind]){
                    // if(inc == 1) cout<<prev2<<' '<<prev1<<' '<<' '<<curr<<' '<<upDown<<'\n';
                    int x = ch == s[ind] ? 0 : -1;
                    ans += f(ind+1, s, e, curr, prev1, x, cnt + inc, nlz2);

                } else if(upDown == 1 && ch <= e[ind]){
                    // if(inc == 1) cout<<prev2<<' '<<prev1<<' '<<' '<<curr<<' '<<upDown<<'\n';
                    int x = ch == e[ind] ? 1 : -1;
                    ans += f(ind+1, s, e, curr, prev1, x, cnt + inc, nlz2);

                } else if(upDown == 2 && ch <= e[ind] && ch >= s[ind]){
                    // if(inc == 1) cout<<prev2<<' '<<prev1<<' '<<' '<<curr<<' '<<upDown<<'\n';
                    int x = (ch==s[ind] and ch==e[ind]) ? 2 :  ch == s[ind] ? 0 : (ch == e[ind] ? 1 : -1);
                    ans += f(ind+1, s, e, curr, prev1, x, cnt + inc, nlz2);
                }
            }
        }
        return dp[r] = ans;
    }

    long long totalWaviness(long long num1, long long num2) {
        
        string s = to_string(num1);
        string e = to_string(num2);
        b = e.size() - s.size();
        while(s.size() < e.size()){
            s = '0' + s;
        }
        int n = s.size();
        return f(0, s, e, -1, -1, -1, 0, 0);
        
    }
};