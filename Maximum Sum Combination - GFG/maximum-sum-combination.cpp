//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        priority_queue<pair<int,int>> pq;
        
        for(int i=0; i<n; i++){
            pq.push({a[i] + b[n-1], n-1});
        }
        
        vector<int> ans;
        while(k-- and !pq.empty()){
            
            auto f = pq.top();
            pq.pop();
            ans.push_back(f.first);
            if(f.second > 0) pq.push({f.first - b[f.second] + b[f.second-1], f.second-1});
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends