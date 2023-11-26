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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();
        DisjointSet *dj = new DisjointSet(n);
        
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({ nums[i], i });
        }
        sort(arr.begin(), arr.end());
        
        for(int i=1; i<n; i++){
            if(arr[i].first-arr[i-1].first <= limit){
                dj->unionByRank(arr[i].second, arr[i-1].second);
            }
        }
        map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for(int i=0; i<n; i++){
            mp[dj->findUPar(i)].push(nums[i]);
        }
        
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            ans[i] = mp[dj->findUPar(i)].top();
            mp[dj->findUPar(i)].pop();
        }
        return ans;
    }
};








