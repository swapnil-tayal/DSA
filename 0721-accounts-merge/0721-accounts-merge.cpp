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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int cnt = 0;
        map<int, string> mp1;
        map<string, int> mp2;
        map<int, string> name;
        
        for(auto i: accounts){
            for(int j=0; j<i.size(); j++){
                if(j == 0) continue;
                mp2[i[j]] = cnt++;
            }
        }
        DisjointSet* dj = new DisjointSet(cnt+1);
        // cout<<mp2["johnsmith@mail.com"]<<' ';
        
        for(auto i: accounts){
            for(int j=0; j<i.size(); j++){
                if(j >= 1){
                    mp1[mp2[i[j]]] = i[j];
                    name[mp2[i[j]]] = i[0];
                }
                if(j <= 1) continue;
                dj->unionByRank(mp2[i[j]], mp2[i[j-1]]);
            }
        }
        map<int,set<int>> finalMp;
        for(auto i: accounts){
            for(int j=0; j<i.size(); j++){
                if(j == 0) continue;
                finalMp[dj->findPar(mp2[i[j]])].insert(mp2[i[j]]);
            }
        }
        
        // for(auto i: finalMp){
        //     for(auto j: i.second) cout<<j<<' ';
        //     cout<<'\n';
        // }
        
        vector<vector<string>> ans;
        for(auto i: finalMp){
            
            vector<string> arr;
            for(auto &j: i.second){
                // cout<<name
                if(arr.size() == 0){
                    arr.push_back(name[j]);
                }
                arr.push_back(mp1[j]);
            }
            sort(arr.begin()+1, arr.end());
            ans.push_back(arr);
        }
        return ans;
    }
};