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

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
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

bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[2] < v2[2];
}

class Solution{
public:
    
    int kruskul(vector<vector<int>> adj, int n, int pick, int npick){
        
        int sum = 0;
        DisjointSet *dj = new DisjointSet(n+1);
        
        if(npick != -1){
            
            sum += adj[npick][2];
            dj->unionByRank(adj[npick][1], adj[npick][0]);
        }
        
        for(int i=0; i<adj.size(); i++){
            
            if(i == pick) continue;
             
            int u = dj->findParent(adj[i][1]);
            int v = dj->findParent(adj[i][0]);
        
            if(u == v) continue;
            sum += adj[i][2];
            dj->unionByRank(adj[i][1], adj[i][0]);        
        }
        
        set<int> st;
        for(int i=0; i<n; i++) st.insert(dj->findParent(i));
        if(st.size() > 1) return 1e9;
        
        return sum;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> ans(2);
        
        for(int i=0; i<edges.size(); i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), cmp);

        int minSum = kruskul(edges, n, -1, -1);
        
        for(int i=0; i<edges.size(); i++){
            
            int newSum = kruskul(edges, n, i, -1);
            if(newSum > minSum) ans[0].push_back(edges[i][3]);
            else{
                newSum = kruskul(edges, n, -1, i);
                if(newSum == minSum) ans[1].push_back(edges[i][3]);
            }
        }
        
        return ans;

    }
};