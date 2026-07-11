class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        
        int n = scores.size();
        vector<vector<int>> adj(n);
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for(int i=0; i<n; i++){
            sort(adj[i].begin(), adj[i].end(), [&](int &a, int &b){
                return scores[a] > scores[b];
            });
            if(adj[i].size() > 3) adj[i].resize(3);
        }

        int ans = -1;
        for(auto &i: edges){

            int u = i[0];
            int v = i[1];

            for(auto &p: adj[u]){
                for(auto &q: adj[v]){

                    if(p == q) continue;
                    if(p == v) continue;
                    if(q == u) continue;
                    ans = max(ans, scores[u] + scores[v] + scores[p] + scores[q]); 
                }
            }
        }
        return ans;
    }
};