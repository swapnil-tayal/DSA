class Solution {
public:
    
    int f(int i, string &str, char currVal,  vector<vector<int>> &dp){
        
        if(i == str.size()){
            if(currVal == '1') return 1e9;
            return 0;
        }
        if(dp[i][currVal-'0'] != -1) return dp[i][currVal-'0'];
        int ans = 0;
        if(str[i] == currVal){
            if(currVal == '1') ans += (pow(2, str.size()-1-i)*2)-1;
            ans += f(i+1, str, '0', dp);
        }
        else{
            
            if(currVal == '0'){
                
                int case1 = (pow(2, str.size()-1-i)*2)-1 + f(i+1, str, '0', dp);
                int case2 = 1 + f(i+1, str, '1', dp);
                ans = min(case1, case2);
                
            }else{
                
                int case1 = 1 + (pow(2, str.size()-1-i)*2)-1 + f(i+1, str, '1', dp);
                int case2 = 2*((pow(2, str.size()-1-i)*2)-1) + f(i+1, str, '0', dp);
                ans = min(case1, case2);
            }
        }return dp[i][currVal-'0'] = ans;
    }
    
    int minimumOneBitOperations(int n) {
        
        string str = "";
        while(n >= 1){
            str = to_string(n%2) + str;
            n /= 2;
        }
        // cout<<str<<'\n';
        vector<vector<int>> dp(str.size(), vector<int>(2, -1));
        return f(0, str, '0', dp);
    }
};