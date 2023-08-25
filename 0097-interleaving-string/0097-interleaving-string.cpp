class Solution {
public:
    
    int f(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        
        if(i+j == s3.size()){
            return (i==s1.size() and j==s2.size());
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int str1 = 0;
        int str2 = 0;
        
        if(i < s1.size() and j < s2.size() and s1[i] == s3[i+j] and s2[j] == s3[i+j]){
            
            str1 = f(i+1, j, s1, s2, s3, dp);
            str2 = f(i, j+1, s1, s2, s3, dp);
        
        }else if(i < s1.size() and s1[i] == s3[i+j]){
            str1 = f(i+1, j, s1, s2, s3, dp);
            
        }else if(j < s2.size() and s2[j] == s3[i+j]){
            str2 = f(i, j+1, s1, s2, s3, dp);
        }
        return dp[i][j] = (str1 || str2);
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<int>> dp(105, vector<int>(105, -1));
        return f(0, 0, s1, s2, s3, dp);    
    }
};