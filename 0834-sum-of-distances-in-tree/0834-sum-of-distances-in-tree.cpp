class Solution {
    vector<int> counter, res;
public:
    
    void dfs2(int src, int n, int par, vector<int> adj[]){
        
        for(auto i: adj[src]){
            if(i == par) continue;
            res[i] = res[src] - counter[i] + n - counter[i];
            dfs2(i, n, src, adj);
        }
    }
    
    void dfs(int src, int par, vector<int> adj[]){
        
        for(auto i: adj[src]){
            if(i == par) continue;
            dfs(i, src, adj);
            counter[src] += counter[i];
            res[src] += res[i] + counter[i];
        }
        counter[src] += 1;
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        counter.resize(n);
        res.resize(n);
        
        dfs(0, -1, adj);
        dfs2(0, n, -1, adj);
        return res;
    }
};