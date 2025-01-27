class Solution {
public:

    int f(int src, int tar, vector<int> &vis, vector<int> adj[]){
        int ans = 0;
        vis[src] = 1;
        if(src == tar) return 1;
        for(auto i: adj[src]){
            if(vis[i]) continue;
            ans = ans || f(i, tar, vis, adj);
        }
        return ans;
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<int> adj[n];
        for(auto &i: prerequisites){
            adj[i[0]].push_back(i[1]);
        }

        vector<bool> ans;
        for(auto &i: queries){
            vector<int> vis(n, 0);
            if(f(i[0], i[1], vis, adj)){
                ans.push_back(true);
            }else ans.push_back(false);
        }
        return ans;
    }
};