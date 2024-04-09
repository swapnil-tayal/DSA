class DisjoinSet{

    vector<int> parent;
    vector<int> size;
    public:

    DisjoinSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int findParent(int n){
        if(parent[n] == n){
            return n;
        }
        return parent[n] = findParent(parent[n]);
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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
        DisjoinSet *dj = new DisjoinSet(n);
        for(auto &i: edges){
            dj->unionBySize(i[0], i[1]);
        }
        
        int cnt = 0;
        set<int> st;
        for(int i=0; i<n; i++) st.insert(dj->findParent(i));
        
        map<int, set<pair<int,int>>> mp1;
        map<int, int> mp2;
        
        for(auto i: edges){
            int par = dj->findParent(i[0]);
            if(mp2.find(par) == mp2.end()){
                mp2[par] = i[2];
            }else mp2[par] = mp2[par] & i[2];
        }
        
        int m = query.size();
        vector<int> a(m, -1);
        for(int i=0; i<m; i++){
            
            int ind1 = query[i][0];
            int ind2 = query[i][1];
            
            if(dj->findParent(ind1) == dj->findParent(ind2)){
                a[i] = mp2[dj->findParent(ind1)];
            }
        }
        return a;
    }
};