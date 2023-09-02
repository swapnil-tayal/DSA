//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  
  int f(int i, int prev, vector<int> &a, vector<vector<int>> &dp){
      
      if(i == a.size()) return 0;
      if(dp[i][prev] != -1) return dp[i][prev];
      
      int pick = 0;
      int npick = 0;
      if(prev == 0){
          
          pick = a[i] + f(i+1, 1, a, dp);
          npick = f(i+1, 0, a, dp);
      
      }else if(prev == 1){
          
          pick = a[i] + f(i+1, 2, a, dp);
          npick = f(i+1, 0, a, dp);
      
      }else if(prev == 2){
          
          npick = f(i+1, 0, a, dp);
      }
      return dp[i][prev] = max(pick, npick);
  }
  
  int findMaxSum(vector<int>& a){
      //Code Here
      vector<vector<int>> dp(a.size(), vector<int>(3, -1));
      return f(0, 0, a, dp);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends