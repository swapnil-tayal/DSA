class Solution {
public:

    void dfs(int src, vector<int> &vis, vector<int> adj[]){

        vis[src] = 1;
        for(auto &i: adj[src]){
            if(vis[i]) continue;
            dfs(i, vis, adj);
        }
        return;
    }

    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        vector<int> adj[n];

        for(int i=0; i<n; i++){
            if(i-arr[i] >= 0){
                adj[i].push_back(i-arr[i]);
            }
            if(i+arr[i] < n){
                adj[i].push_back(i+arr[i]);
            }
        }
        vector<int> vis(n, 0);
        dfs(start, vis, adj);
        for(int i=0; i<n; i++){
            if(arr[i] == 0 and vis[i] == 1) return true;
        }
        return false;
    }
};