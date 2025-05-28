class Solution {
public:

    void f(int src, int par, vector<vector<int>> &adj, int &cnt, int k){
        if(k <= 0) return;
        for(auto i: adj[src]){
            if(i == par) continue;
            cnt++;
            f(i, src, adj, cnt, k-1);
        }
        return;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        
        int m = edges2.size() + 1;
        int n = edges1.size() + 1;
        vector<vector<int>> adj2(m);
        vector<vector<int>> adj1(n);
        for(auto i: edges2){
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        for(auto i: edges1){
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        int maxCnt = 0;
        for(int i=0; i<m; i++){
            int cnt = (k>0) ? 1: 0;
            f(i, -1, adj2, cnt, k-1);
            maxCnt = max(maxCnt, cnt);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){   
            int currCnt = 1;
            f(i, -1, adj1, currCnt, k);
            cout<<currCnt<<' ';
            ans.push_back(currCnt + maxCnt);
        }
        return ans; 
    }
};