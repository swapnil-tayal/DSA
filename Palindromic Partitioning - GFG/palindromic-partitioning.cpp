//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isPalidrome(string &s){
        
        int n = s.size()-1;
        int i = 0;
        while(i <= n){
            
            if(s[i] != s[n]) return false;
            else{
                i++; n--;
            }
        }
        return true;
    }

    int f(int i, string &s, vector<int> &dp){
        
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        string temp = "";
        int ans = 1e9;
        
        for(int k=i; k<s.size(); k++){
            temp += s[k];
            if(isPalidrome(temp)){
                ans = min(ans, 1 + f(k+1, s, dp));
            }
        }
        return dp[i] = ans;
    }

    int palindromicPartition(string str){
        // code here
        vector<int> dp(str.size(), -1);
        return f(0, str, dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends