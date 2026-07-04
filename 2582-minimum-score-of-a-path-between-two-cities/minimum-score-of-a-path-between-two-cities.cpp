class Solution {
    int ans = 1e9;
public:

    void dfs(int src, vector<pair<int,int>> adj[], vector<int> &vis){

        vis[src] = 1;
        for(auto &i: adj[src]){
            ans = min(ans, i.second);
            if(vis[i.first]) continue;
            dfs(i.first, adj, vis);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> adj[n+1];
        for(auto &i: roads){
            adj[i[0]].push_back({ i[1], i[2] });
            adj[i[1]].push_back({ i[0], i[2] });
        }

        vector<int> vis(n+1, 0);
        dfs(1, adj, vis);
        return ans;
    }
};