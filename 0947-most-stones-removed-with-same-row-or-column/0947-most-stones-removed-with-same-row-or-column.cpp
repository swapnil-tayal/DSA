class DSU{
    vector<int> parent;
    vector<int> size;
    public:
    DSU(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 0);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findParent(int n){
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
    void unionBySize(int x, int y){
        int v = findParent(x);
        int u = findParent(y);
        if(u == v) return;
        if(size[v] > size[u]){
            parent[u] = v;
            size[v] += size[u];
        }else{
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int row = 0;
        int col = 0;
        for(auto i: stones){
            row = max(row, i[0]);
            col = max(col, i[1]);
        }
        DSU *ds = new DSU(row + col + 2);
        set<int> having;
        
        for(auto i: stones){
            
            int r = i[0];
            int c = i[1];
            ds->unionBySize(r, c + row + 1);
            having.insert(r);
            having.insert(c+row+1);
        }
        set<int> st;
        for(auto i: having){
            st.insert(ds->findParent(i));
        }
        return stones.size() - st.size();
    }
};