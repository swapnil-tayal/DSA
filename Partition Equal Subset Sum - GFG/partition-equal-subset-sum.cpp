//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int f(int i, int arr[], int sum, vector<vector<int>> &dp){
        
        if(sum < 0) return 0;
        if(i == -1) return sum == 0;
    
        if(dp[i][sum] != -1) return dp[i][sum]; 
        
        int pick = f(i-1, arr, sum-arr[i], dp);
        int npick = f(i-1, arr, sum, dp);
        return dp[i][sum] =  (pick || npick);
    }

    int equalPartition(int n, int arr[]){
        // code here
        
        int sum = 0;
        for(int i=0; i<n; i++) sum += arr[i];

        if(sum%2) return 0;
        
        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
        return f(n-1, arr, sum/2, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends