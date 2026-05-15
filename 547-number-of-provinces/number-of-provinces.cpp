class Solution {
public:

    void dfs(int src, vector<vector<int>> &isConnected, vector<int> &vis){

        int n = vis.size();
        vis[src] = 1;
        for(int i=0; i<n; i++){
            if(src != i && isConnected[src][i] and vis[i] == 0){
                dfs(i, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                cnt++;
                dfs(i, isConnected, vis);
            }
        }
        return cnt;
    }
};