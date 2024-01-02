class Solution {
    int cntVal(int cnt){
        int val = 0;
        if(cnt == 1) val = 1;
        else if(cnt < 10 and cnt > 1) val = 2;
        else if(cnt < 100 and cnt > 9) val = 3;
        else if(cnt == 100) val = 4;
        return val;
    }
public:
    
    int f(int i, int prev, int k, string &s, vector<vector<vector<int>>> &dp, vector<vector<vector<int>>> &pre){
        
        if(k < 0) return 1e9;
        if(i == s.size()){
            if(prev == -1) return 0;
            return cntVal(pre[prev][i-1][s[prev]-'a']);
        }
        
        if(dp[i][prev+1][k] != -1) return dp[i][prev+1][k];
        
        int ans = 0;
        if(prev == -1){
            int skip = f(i+1, -1, k-1, s, dp, pre);
            int newChar = f(i+1, i, k, s, dp, pre);
            // cout<<skip<<' '<<newChar<<'\n';
            return dp[i][prev+1][k] = min(skip, newChar);
            
        }else{
            if(s[i] == s[prev]) return dp[i][prev+1][k] = f(i+1, prev, k, s, dp, pre);
            else{
                // cout<<ch<<' '<<s[i]<<'\n';
                int skip = f(i+1, prev, k-1, s, dp, pre);
                int pick = cntVal(pre[prev][i][s[prev]-'a']) + f(i+1, i, k, s, dp, pre);
                return dp[i][prev+1][k] = min(skip, pick);
            }
        }
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        
        int n = s.size();
        vector<vector<vector<int>>> pre(n, vector<vector<int>>(n, vector<int>(26, 0)));
        
        for(int i=0; i<n; i++){
            map<char,int> mp;
            for(int j=i; j<n; j++){
                mp[s[j]]++;
                for(auto h: mp){
                    pre[i][j][h.first - 'a'] = h.second;
                }
            }
        }
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        return f(0, -1, k, s, dp, pre);
    }
};