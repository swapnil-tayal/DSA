class Solution {
    string str;
    string fin;
    string s;
    char limit;
public:
    
    long long f(int i, int f1, int f2, vector<vector<vector<long long>>> &dp){
        
        if(i == s.size()) return 1;
        
        long long ans = 0;
        if(dp[i][f1][f2] != -1) return dp[i][f1][f2];
        
        if(f1 == 0 and f2 == 0){
            
            if(s[i] != '.'){
                if(s[i] > limit) ans = 0;
                else if(s[i] == str[i] and s[i] == fin[i]) ans += f(i+1, 0, 0, dp);
                else if(s[i] == str[i]) ans += f(i+1, 0, 1, dp);
                else if(s[i] == fin[i]) ans += f(i+1, 1, 0, dp);
                else if(s[i] > str[i] and s[i] < fin[i]) ans += f(i+1, 1, 1, dp);
            
            }else{
                if(str[i] == fin[i]){
                    if(str[i] > limit) ans = 0;
                    else ans += f(i+1, 0, 0, dp);
                }
                else{     
                    if(str[i] <= limit) ans += f(i+1, 0, 1, dp);
                    for(char ch=str[i]+1; ch <= min((int)limit, fin[i]-1); ch++){
                        ans += f(i+1, 1, 1, dp);
                    }
                    if(fin[i] <= limit) ans += f(i+1, 1, 0, dp);
                }
            }
        
        }else if(f1 == 1 and f2 == 0){
            
            if(s[i] != '.'){
                if(s[i] > limit) ans = 0;
                else if(s[i] == fin[i]) ans += f(i+1, 1, 0, dp);
                else if(s[i] < fin[i]) ans += f(i+1, 1, 1, dp);
            
            }else{
                if(fin[i] <= limit) ans += f(i+1, 1, 0, dp);
                for(char ch='0'; ch <= min((int)limit, fin[i]-1); ch++){
                    ans += f(i+1, 1, 1, dp);
                }
            }
        
        }else if(f1 == 0 and f2 == 1){
            
            if(s[i] != '.'){                
                if(s[i] > limit) ans = 0;
                else if(s[i] == str[i]) ans += f(i+1, 0, 1, dp);
                else if(s[i] > str[i]) ans += f(i+1, 1, 1, dp);
            
            }else{
                if(str[i] <= limit) ans += f(i+1, 0, 1, dp);
                for(char ch=str[i]+1; ch<= min((int)limit, (int)'9'); ch++){
                    ans += f(i+1, 1, 1, dp);
                }
            }
        
        }else{
            
            if(s[i] != '.'){ 
                if(s[i] > limit) ans = 0;
                else ans += f(i+1, 1, 1, dp);
            }else{
                for(char ch='0'; ch <= min(limit, '9'); ch++){
                    ans += f(i+1, 1, 1, dp);
                }
            }
        }
        return dp[i][f1][f2] = ans;
    }
    
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        
        this->str = to_string(start);
        this->fin = to_string(finish);
        this->limit = limit + '0';
        cout<<this->limit<<'\n';
        
        while(str.size() < fin.size()){
            str = "0" + str;
        }
        string myStr = s;
        while(myStr.size() < str.size()){
            myStr = "." + myStr;
        }
        this->s = myStr;
        int n = str.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2, vector<long long>(2, -1)));
        return f(0, 0, 0, dp);
        return 0;
    }
};