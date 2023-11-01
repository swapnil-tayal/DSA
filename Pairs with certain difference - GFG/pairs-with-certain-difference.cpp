//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int f(int i, int arr[], int k, int n, vector<int> &dp){
        
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int npick = f(i+1, arr, k, n, dp);
        int pick = 0;
        if(i+1 < n and abs(arr[i] - arr[i+1]) < k){
            pick = arr[i] + arr[i+1] + f(i+2, arr, k, n, dp);
        }
        return dp[i] = max(npick, pick);
    }
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K){
        // Your code goes here   
        sort(arr, arr+N);
        vector<int> dp(N, -1);
        return f(0, arr, K, N, dp);
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends