class DisjoinSet{

    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    public:

    DisjoinSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int n){
        if(parent[n] == n){
            return n;
        }
        return parent[n] = findParent(parent[n]);
    }
    void unionByRank(int u, int v){

        u = findParent(u);
        v = findParent(v);
        if(u == v)return;
        if(rank[v] < rank[u]){
            parent[v] = u;
        }else if(rank[u] < rank[v]){
            parent[u] = v;
        }else{
            parent[v] = u;
            rank[u]++;
        }
    }
    void unionBySize(int u, int v){

        u = findParent(u);
        v = findParent(v);
        if(u == v)return;
        if(size[v] < size[u]){
            parent[v] = u;
            size[u] += size[v];
        }else{
            parent[u] = v;
            size[v] += size[u];
        }
    }

};

class Solution {
public:
    
    void dfs(int src, vector<pair<int,int>> adj[], int type, vector<int> &vis){
        
        vis[src] = 1;
        for(auto i: adj[src]){
            if(vis[i.first] == 0 and i.second != type){
                dfs(i.first, adj, type, vis);
            }
        }
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        vector<pair<int,int>> adj[n+1];
        int cnt = 0;
        for(auto i: edges){
            adj[i[1]].push_back({ i[2],i[0] });
            adj[i[2]].push_back({ i[1],i[0] });
            if(i[0] == 3) cnt++;
        }
        
        vector<int> vis1(n+1,0);
        dfs(1, adj, 2, vis1);
        for(int i=1; i<=n; i++){
            if(vis1[i] == 0) return -1;
        }
        vector<int> vis2(n+1,0);
        dfs(1, adj, 1, vis2);
        for(int i=1; i<=n; i++){
            if(vis2[i] == 0) return -1;
        }
        
        DisjoinSet *dj = new DisjoinSet(n+1);
        for(auto i: edges){
            if(i[0] == 3) dj->unionByRank(i[1], i[2]);
        }
        
        map<int,int> mp;
        for(int i=1; i<=n; i++) mp[dj->findParent(i)]++;
        
        int cnt2 = 0;
        int maxi = 0;
        for(auto i: mp){
            maxi += i.second-1;
        }
        cnt2 = max(0,cnt -maxi);
        
        return edges.size() - (cnt + (mp.size()-1)*2) + cnt2;
    }
};