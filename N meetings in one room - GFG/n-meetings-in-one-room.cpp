//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int f(int i, vector<pair<int,int>> &arr, vector<int> &str, vector<int> &dp){
        
        if(i == arr.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        int ind = lower_bound(str.begin(), str.end(), arr[i].second+1) - str.begin();
        int pick = 1 + f(ind, arr, str, dp);
        int npick = f(i+1, arr, str, dp);
        
        return dp[i] = max(pick, npick);
    }
    
    int maxMeetings(int start[], int end[], int n){
        // Your code here
        
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({ start[i], end[i] });
        }
        sort(arr.begin(), arr.end());
        vector<int> str;
        for(int i=0; i<n; i++){
            str.push_back(arr[i].first);
        }
        vector<int> dp(n, -1);
        return f(0, arr, str, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends