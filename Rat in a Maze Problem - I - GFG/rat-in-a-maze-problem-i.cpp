//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    
     vector<int> row = {1, 0, 0, -1};
     vector<int> col = {0, -1, 1, 0};
    public:
    
    void f(int i, int j, vector<vector<int>> &m, vector<string> &ans, string temp, 
                    vector<vector<int>> &vis){
        
        int n = m.size();
        if(i == n-1 and j == n-1){
            ans.push_back(temp);
            return;
        }
        
        string dir = "DLRU";
        for(int k=0; k<4; k++){
            
            int newi = i + row[k];
            int newj = j + col[k];
            
            if(newi >= 0 and newj >= 0 and newi < n and newj < n and m[newi][newj] == 1 and vis[newi][newj] == 0){
                vis[newi][newj] = 1;
                f(newi, newj, m, ans, temp+dir[k], vis);
                vis[newi][newj] = 0;
            }
        }
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<string> ans;
        
        if(m[0][0] == 0) return {"-1"};
        
        vis[0][0] = 1;
        f(0, 0, m, ans, "", vis);
        return ans;
    }
};

    



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends