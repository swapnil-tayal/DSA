//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<int> ans;
  public:
  
    int dfs(int src, vector<int> &dfsVis, vector<int> adj[], vector<int> &vis, vector<int> &cycle){
        
        vis[src] = 1;
        dfsVis[src] = 1;
        
        for(auto i: adj[src]){
            
            if(!vis[i]){
                if(dfs(i, dfsVis, adj, vis, cycle)){
                    cycle[src] = 1;
                    return 1;
                }
            }else if(dfsVis[i]){
                cycle[src] = true;
                return 1;
            }
        }
        dfsVis[src] = 0;
        return 0;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        int n = V;
        vector<int> vis(n, 0);
        vector<int> dfsVis(n, 0);
        vector<int> cycle(n, 0);
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(vis[i]) continue;
            dfs(i, dfsVis, adj, vis, cycle);
        }
        
        for(int i=0; i<n; i++){
            if(!cycle[i]) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends