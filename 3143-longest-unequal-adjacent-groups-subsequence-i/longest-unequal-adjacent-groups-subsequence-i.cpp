class Solution {
public:

    string f(int i, int prev, vector<string> &str, vector<int> &num, vector<vector<string>> &dp){

        if(i == str.size()) return "";
        if(dp[i][prev] != "-1") return dp[i][prev];
        string pick = "";
        string npick = f(i+1, prev, str, num, dp);
        if(i == 0 || num[prev] != num[i]){
            pick = str[i] + "-" + f(i+1, i, str, num, dp);
        }
        if(npick.size() > pick.size()) return dp[i][prev] = npick;
        else return dp[i][prev] = pick;
    }

    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        int n = words.size();
        vector<vector<string>> dp(n, vector<string>(n, "-1"));
        string str = f(0, 0, words, groups, dp);
        // cout<<str<<'\n';
        vector<string> ans;
        int i = 0;
        while(i < str.size()){
            string temp = "";
            if(str[i] == '-') i++;
            while(i<str.size() and str[i] != '-'){
                temp += str[i];
                i++;
            }
            // cout<<temp<<'\n';
            if(temp.size()) ans.push_back(temp);
        }
        return ans;
    }
};