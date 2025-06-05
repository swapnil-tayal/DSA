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
    string smallestEquivalentString(string s1, string s2, string baseStr) {

        DisjointSet* dj = new DisjointSet(26);
        for(int i=0; i<s1.size(); i++){
            dj->unionByRank(s1[i]-'a', s2[i]-'a');
        }
        map<char,set<char>> mp;
        for(int i=0; i<26; i++){
            int par = dj->findUPar(i);
            mp[par+'a'].insert(char(i+'a'));
        }
        // for(auto i: mp){
        //     cout<<i.first<<'-';
        //     for(auto k: i.second) cout<<k<<' ';
        //     cout<<'\n';
        // }
        string str = "";
        for(int i=0; i<baseStr.size(); i++){
            str += *mp[char(dj->findUPar(baseStr[i]-'a') + 'a')].begin();
        }
        return str;
    }
};