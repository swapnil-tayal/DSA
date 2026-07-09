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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        DisjointSet *dj = new DisjointSet(n);

        int i = 0;
        while(i < n){
            int maxInd = upper_bound(nums.begin(), nums.end(), nums[i] + maxDiff) - nums.begin() - 1;
            for(int k=i; k<=maxInd; k++){
                dj->unionByRank(i, k);
            }
            if(maxInd == i) i++;
            else i = maxInd;
        }
        vector<bool> ans;
        for(auto &i: queries){
            if(dj->findPar(i[0]) == dj->findPar(i[1])){
                ans.push_back(true);
            }else ans.push_back(false);
        }
        return ans;
    }
};