class Solution {
    vector<int> values;
    int k;
    int ans;
public:

    long long f(int src, vector<vector<int>> &adj, int par){

        long long sum = 0;
        for(auto &i: adj[src]){
            if(i == par) continue;
            sum += f(i, adj, src);
        }
        sum += values[src];
        if(sum % k == 0){
            sum = 0;
            ans++;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        this->values = values;
        this->k = k;
        this->ans = 0;
        vector<vector<int>> adj(n);
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        f(0, adj, -1);
        return ans;
    }
};