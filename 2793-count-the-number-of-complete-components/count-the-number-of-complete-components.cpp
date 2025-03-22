class Solution {
public:

    void f(int src, vector<int> &vis, vector<int> adj[], vector<int> &arr){
        arr.push_back(src);
        vis[src] = 1;
        for(auto &i: adj[src]){
            if(vis[i] == 1) continue;
            f(i, vis, adj, arr);
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
            vector<int> arr;
            f(i, vis, adj, arr);
            int f = 0;
            for(int k=0; k<arr.size(); k++){
                for(int j=k+1; j<arr.size(); j++){
                    if(st.count({arr[j], arr[k]}) == 0 and st.count({arr[k], arr[j]}) == 0){
                        f = 1;  
                    }
                }
            }
            if(!f) cnt++;
        }
        return cnt;
    }
};