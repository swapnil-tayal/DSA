class DisjointSet {
    vector<int> rank, parent;
    public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:

    void dfs(int src, vector<int> adj[], vector<int> &vis){
        vis[src] = 1;
        for(auto &i: adj[src]){
            if(vis[i]) continue;
            dfs(i, adj, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<int> adj[n];
        DisjointSet *dj = new DisjointSet(n);
        for(auto &i: invocations){
            adj[i[0]].push_back(i[1]);
            dj->unionByRank(i[0], i[1]);
        }

        vector<int> suspicious(n, 0);
        dfs(k, adj, suspicious);
        int parS = dj->findPar(k);
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(!suspicious[i] and dj->findPar(i) == parS){
                vector<int> ans;
                for(int p=0; p<n; p++) ans.push_back(p);
                return ans;
            }else if(!suspicious[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};