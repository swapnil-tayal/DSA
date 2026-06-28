class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        DSU *dj = new DSU(n*m);
        int row[] = {-1,1,0,0};
        int col[] = {0,0,-1,1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) continue;
                int q1 = (i*m) + j;
                for(int k=0; k<4; k++){

                    int newi = i + row[k];
                    int newj = j + col[k];
                    if(newi >= 0 and newj >= 0 and newi < n and newj < m and grid[newi][newj] == 1){
                        int q2 = (newi*m) + newj;
                        dj->unionBySize(q1, q2);
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n*m; i++){
            ans = max(ans, dj->size[dj->findUPar(i)]);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) continue;

                set<int> st;
                for(int k=0; k<4; k++){

                    int newi = i + row[k];
                    int newj = j + col[k];
                    if(newi >= 0 and newj >= 0 and newi < n and newj < m and grid[newi][newj] == 1){
                    
                        int q2 = (newi*m) + newj;
                        st.insert(dj->findUPar(q2));
                    }
                }
                int sum = 0;
                for(auto k: st){
                    sum += dj->size[k];
                }
                ans = max(ans, sum+1);
            }
        }
        return ans;
    }
};