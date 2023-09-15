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
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<vector<int>> adj;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                // adj.push_back({x, j, i});
                // adj.push_back({x, i, j});
                pq.push({x, {i, j}});
                pq.push({x, {j, i}});
            }    
        }
        DisjointSet *dj = new DisjointSet(n+1);
        int sum = 0;
        
        while(!pq.empty()){
            
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            int dis = pq.top().first;
            pq.pop();
            
            if(dj->findPar(u) == dj->findPar(v)) continue;
            sum += dis;
            dj->unionByRank(u, v);
        }
        return sum;
    }
};  