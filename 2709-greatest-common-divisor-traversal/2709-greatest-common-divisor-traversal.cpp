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
#define MAXN 100001
vector<long long> spf(MAXN);
long long sieve() {
    spf[1] = 1;
    for (long long i = 2; i < MAXN; i++) spf[i] = i;

    for (long long i = 4; i < MAXN; i += 2) spf[i] = 2;

    for (long long i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (long long j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    return 1;
}
set<int> getFactorization(long long x) {
    set<int> ret;
    while (x != 1) {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

class Solution {
public:
    
    Solution(){
        sieve();
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        
        int n = nums.size();
        DisjoinSet *dj = new DisjoinSet(n);
        
        map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            
            set<int> fac = getFactorization(nums[i]);
            for(auto &k: fac) mp[k].push_back(i);
        }
        for(auto i: mp){
            vector<int> arr = i.second;
            for(int k=1; k<arr.size(); k++){
                dj->unionBySize(arr[k], arr[k-1]);
            }
        }
        set<int> st;
        for(int i=0; i<n; i++) st.insert(dj->findParent(i));
        return st.size() == 1;
    }
};


