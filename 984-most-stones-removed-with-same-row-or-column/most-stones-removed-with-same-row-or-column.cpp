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
    int removeStones(vector<vector<int>>& stones) {

        int n = 0;
        int m = 0;
        for(auto &i: stones){
            n = max(n, i[0]);
            m = max(m, i[1]);
        }

        DSU *dj = new DSU((n + m + 2));
        for(auto &i: stones){
            int row = i[0];
            int col = n + i[1] + 1;
            dj->unionBySize(row, col);
        }
        set<int> st;
        for(auto &i: stones){
            int row = i[0];
            int col = n + i[1] + 1;
            st.insert(dj->findUPar(row));
            st.insert(dj->findUPar(col));
        }
        return stones.size() - st.size();
    }
};