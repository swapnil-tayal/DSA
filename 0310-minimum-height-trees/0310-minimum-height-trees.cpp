class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(edges.size() == 1){
            return { edges[0][0], edges[0][1] };
        }
        if(edges.size() == 0) return { 0 };
        
        vector<int> adj[n];
        vector<int> inD(n, 0);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            inD[i[0]]++;
            inD[i[1]]++;
        }
        
        vector<int> vis(n, 0);
        queue<int> q;
        set<int> st;
        
        for(int i=0; i<n; i++){
            if(inD[i] == 1){
                q.push(i);
                inD[i] = 0;
                vis[i] = 1;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            
            int m = q.size();
            while(m--){
                int node = q.front();
                q.pop();

                for(auto i: adj[node]){
                    inD[i]--;
                    if(inD[i] == 1) q.push(i);
                }
            }
            if(q.size() == 1 || q.size() == 2){
                ans.clear();
                while(!q.empty()){
                    ans.push_back(q.front());
                    q.pop();
                }
                for(auto i: ans) q.push(i);
            }
        }
        return ans;
    }
};