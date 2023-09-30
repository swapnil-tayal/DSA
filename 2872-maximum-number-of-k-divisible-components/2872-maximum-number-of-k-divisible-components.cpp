class Solution {
    int ans;
    int k;
public:
    
    int dfs(int src, vector<int> adj[], vector<int> &values, vector<int> &vis){
        
        int sum = values[src];
        vis[src] = 1;
        for(auto i: adj[src]){
            if(vis[i]) continue;
            sum += dfs(i, adj, values, vis);
        }
        if(sum % k == 0){
            sum = 0;
            ans++;
        }
        return sum;
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<int> adj[n];
        ans = 0;
        this->k = k;
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n, 0);
        dfs(0, adj, values, vis);
        return ans;
    }
};