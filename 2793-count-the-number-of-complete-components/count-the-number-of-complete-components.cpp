class Solution {
public:

    void f(int src, vector<int> &vis, vector<int> adj[], int &cnt, int &edges){
        cnt++;
        vis[src] = 1;
        for(auto &i: adj[src]){
            edges++;
            if(vis[i] == 1) continue;
            f(i, vis, adj, cnt, edges);
        }
        return;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        set<pair<int,int>> st;
        for(auto i: edges){
            st.insert({ i[0] , i[1]});
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(vis[i] == 1) continue;                
            int ver = 0;
            int edges = 0;
            f(i, vis, adj, ver, edges);
            cnt += ((ver*(ver-1)/2) == (edges/2));
        }
        return cnt;
    }
};