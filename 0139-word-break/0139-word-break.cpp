class Solution{
    set<string> st;
public:
    
    int ch(int i, int j, string &str){
        string temp = "";
        for(int k=i; k<=j; k++) temp += str[k];
        return st.count(temp);
    }
    
    int f(int i, int prev, string &str, vector<vector<int>> &dp){
        
        if(i == str.size()) return prev == str.size();
        if(dp[i][prev] != -1) return dp[i][prev];
        int npick = f(i+1, prev, str, dp);
        int pick = 0;
        if(ch(prev, i, str)) pick = f(i+1, i+1, str, dp);
        return dp[i][prev] = npick or pick;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for(auto i: wordDict) st.insert(i);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, s, dp);
    }
};