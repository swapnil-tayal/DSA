class Solution {
public:
    
    int f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        
        if(i == -1){
            if(j != -1){
                if(j%2 == 0) return 0;
                else{
                    while(j > 0){
                        if(p[j] != '*') return 0;
                        j-=2;
                    }return 1;
                }
            }
            else return  j == -1;
        }
        if(i == -1 || j == -1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(p[j] != '*' and p[j] != '.'){
            
            if(s[i] != p[j]) return 0;
            else return dp[i][j] = f(i-1, j-1, s, p, dp);
            
        }else if(p[j] == '.'){
            
            return dp[i][j] = f(i-1, j-1, s, p, dp);
            
        }else{
            
            int ch = p[j-1];
            if(ch != '.'){
                
                if(s[i] != ch){
                    return dp[i][j] = f(i, j-2, s, p, dp);
                }
                else{
                    int pickNow = f(i-1, j-2, s, p, dp);
                    int npickNow = f(i-1, j, s, p, dp);
                    int zeropickNow = f(i, j-2, s, p, dp);
                    return dp[i][j] = pickNow || npickNow || zeropickNow;
                }
                
            }else{
                int pickNow = f(i-1, j-2, s, p, dp);
                int npickNow = f(i-1, j, s, p, dp);
                int zeropickNow = f(i, j-2, s, p, dp);
                return dp[i][j] = pickNow || npickNow || zeropickNow;
            }
        }
    }
    
    bool isMatch(string s, string p) {
        
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return f(s.size()-1, p.size()-1, s, p, dp);
    }
};