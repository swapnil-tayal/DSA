class DSU{
    vector<int> size;
    vector<int> parent;
    public:
    DSU(int n){
        size.resize(n+1, 0);
        parent.resize(n+1, 0);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findParent(int n){
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
    void unionBySize(int x, int y){
        int u = findParent(x);
        int v = findParent(y);
        if(u == v) return;
        if(size[u] > size[v]){
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