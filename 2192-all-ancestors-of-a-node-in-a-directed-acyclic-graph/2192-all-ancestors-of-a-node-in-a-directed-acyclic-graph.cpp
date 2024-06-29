class Solution {
public:
    
    void dfs(int src, vector<int> &arr, vector<int> adj[], vector<int> &vis){
        
        vis[src] = 1;
        for(auto i: adj[src]){
            if(!vis[i]){
                arr.push_back(i);
                dfs(i, arr, adj, vis);
            }
        }
        return;
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        for(auto i: edges){
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){
            vector<int> arr = {};
            vector<int> vis(n, 0);
            dfs(i, arr, adj, vis);
            sort(arr.begin(), arr.end());
            ans.push_back(arr);
        }
        return ans;
    }
};