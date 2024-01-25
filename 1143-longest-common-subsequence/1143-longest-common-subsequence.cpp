class Solution {
public:
    
    int f(int i, int j, string &str1, string &str2, vector<vector<int>> &dp){
        
        if(i == -1 || j == -1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int pick = 0;
        if(str1[i] == str2[j]){
            pick = 1 + f(i-1, j-1, str1, str2, dp);
        }
        int npcik = max(f(i-1, j, str1, str2, dp), f(i, j-1, str1, str2, dp));
        return dp[i][j] = max(pick, npcik);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        
        string str;
        int i = text1.size()-1, j = text2.size()-1;
        int ans = f(text1.size()-1, text2.size()-1, text1, text2, dp);
        
//         while(i >= 0 and j >= 0){
            
//             if(text1[i] == text2[j]){
//                 str = text1[i] + str;
//                 i--; j--;
//             }else{
                
//                 if(j-1 == -1) i--;
//                 else if(i-1 == -1) j--;
//                 else if(dp[i-1][j] == dp[i][j]) i--;
//                 else j--;
//             }
//         }
        // cout<<str.size()<<' ';
        // cout<<str<<'\n';
        return ans;
    }
};