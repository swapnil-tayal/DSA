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

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
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
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int> par[n];
        DisjointSet *dj = new DisjointSet(n);
        
        for(int i=0; i<n; i++){
            
            if(leftChild[i] != -1){
                if(par[leftChild[i]].size()) return 0;
                par[leftChild[i]].push_back(i);
                dj->unionByRank(leftChild[i], i);
            }
            if(rightChild[i] != -1){
                if(par[rightChild[i]].size()) return 0;
                par[rightChild[i]].push_back(i);
                dj->unionByRank(rightChild[i], i);
            }
        }
        
        set<int> st;
        for(int i=0; i<n; i++){
            st.insert(dj->findUPar(i));
        }
        if(st.size() > 1) return 0;
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(par[i].size() == 0) cnt++;
            if(cnt > 1) return 0;
        }
        return cnt==1;
    }
};