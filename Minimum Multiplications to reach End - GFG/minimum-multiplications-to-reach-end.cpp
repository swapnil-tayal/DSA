//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        vector<int> vis(100001, 0);
        queue<int> q;
        q.push(start);
        int cnt = 0;
        vis[start] = 1;
        
        while(!q.empty()){
            
            int n = q.size();
            int f = 1;
            
            while(n--){
                
                int start = q.front();
                q.pop();
                
                if(start == end) return cnt;
                for(auto it: arr){
                    
                    int x = (it * start) % 100000;
                    
                    if(vis[x]) continue;
                    vis[x] = 1;
                    
                    f = 0;
                    q.push(x);
                }
                
            }cnt++;
            if(f) break;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends