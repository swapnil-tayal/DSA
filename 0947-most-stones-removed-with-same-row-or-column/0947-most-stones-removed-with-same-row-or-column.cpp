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
    int removeStones(vector<vector<int>>& stones) {
        
        int n = 0;
        int m = 0;
        for(auto i: stones){
            n = max(n, i[0]);
            m = max(m, i[1]);
        }
        // cout<<n<<' '<<m<<'\n';
        DisjoinSet *dj = new DisjoinSet(n+m+2); 
        map<int,int> mp, mp2;
        
        for(auto &i: stones){
            
            int row = i[0];
            int col = i[1] + n + 1;
            dj->unionBySize(row, col);
            mp[row] = 1;
            mp[col] = 1;
        }
        set<int> st;
        for(auto i: mp){
            st.insert(dj->findParent(i.first));
        }
        return stones.size() - st.size();
    }
};








