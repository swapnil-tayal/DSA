class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        queue<vector<int>> q;
        q.push({0, 0, 0});
        
        set<int> st;
        for(auto &i: forbidden) st.insert(i);
        vector<vector<int>> vis(10000, vector<int>(2, 0));
        
        while(!q.empty()){
            
            int node = q.front()[0];
            int dis = q.front()[1];
            int isBack = q.front()[2];
            
            if(node == x) return dis;
            
            q.pop(); 
            if(node >= 10000 || node < 0) continue;
            if(vis[node][isBack]) continue;
            if(st.count(node)) continue;
            
            vis[node][isBack] = 1;
            q.push({ node+a, dis+1 , 0});
            if(isBack == 0) q.push({ node-b, dis+1 , 1});
        }
        return -1;
    }
};