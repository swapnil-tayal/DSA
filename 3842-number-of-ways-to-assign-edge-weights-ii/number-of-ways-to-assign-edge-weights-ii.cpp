class LCA {
    int n, LOG;
    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;

    void dfs(int node, int par) {
        up[node][0] = par;

        for (int j = 1; j < LOG; j++) {
            if (up[node][j - 1] != -1)
                up[node][j] = up[up[node][j - 1]][j - 1];
            else
                up[node][j] = -1;
        }

        for (auto child : adj[node]) {
            if (child == par) continue;

            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }

public:
    LCA(int N, vector<vector<int>>& edges, int root = 0) {
        n = N;
        LOG = 1;

        while ((1 << LOG) <= n) LOG++;

        adj.resize(n);
        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG, -1));

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(root, -1);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);
        int diff = depth[u] - depth[v];
        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j))
                u = up[u][j];
        }
        if (u == v) return u;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
};

class Solution {
public:

    void f(int src, int par, int ht, vector<vector<int>> &adj, vector<int> &depth){
        depth[src] = ht;
        for(auto &i: adj[src]){
            if(i == par) continue;
            f(i, src, ht+1, adj, depth);
        }
        return;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        int n = edges.size()+2;
        vector<vector<int>> adj(n);
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> depth(n, 0);
        f(1, -1, 0, adj, depth);
        LCA tree(n, edges, 1);

        vector<int> pow(n);
        long long x = 1;
        for(int i=0; i<n; i++){
            pow[i] = x;
            x = (x * 2) % (long long)(1e9 + 7);
        }
        vector<int> ans;
        for(auto &i: queries){

            int dis = 0;
            if(i[0] > i[1]) swap(i[0], i[1]);
            int lca = tree.lca(i[0],i[1]);
            if(lca == i[0] || lca == i[1]){
                dis = depth[i[1]] - depth[i[0]];
            }else{
                dis = depth[i[0]] - depth[lca] + depth[i[1]] - depth[lca];
            }
            if(dis == 0) ans.push_back(0);
            else ans.push_back(pow[dis-1]);
        }
        return ans;
    }
};