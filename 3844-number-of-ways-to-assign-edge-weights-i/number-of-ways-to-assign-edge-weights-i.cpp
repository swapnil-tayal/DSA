class Solution {
public:

    int f(int src, int par, vector<vector<int>> &adj){
        int height = 0;
        for(auto &i: adj[src]){
            if(i == par) continue;
            height = max(height, f(i, src, adj));
        }
        return height + 1;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int depth = f(1, -1, adj);
        cout<<depth<<'\n';
        long long ans = 1;
        for(int i=1; i<=depth-2; i++){
            ans = (ans * 2) % (long long)(1e9+7);
        }
        return ans;
    }
};