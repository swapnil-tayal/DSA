class Solution {
public:
    
    int f(int src, vector<int> &vis, vector<int> adj[], vector<vector<pair<int,int>>> &subTree, vector<int> &ans){
        
        vis[src] = 1;
        int maxValue = 0;
        for(auto i: adj[src]){
            
            if(vis[i] == 1) continue;
            int val = ((i%2 == 0) ? 2 : 1) + f(i, vis, adj, subTree, ans);
            maxValue = max(maxValue, val);
            subTree[src].push_back({val, i});     
        }
        ans[src] = maxValue;
        return maxValue;
    }
    
    void f2(int src, vector<int> &vis, vector<int> adj[], vector<vector<pair<int,int>>> &subTree, vector<int> &ans, int topsAns){
        
        vis[src] = 1;
        priority_queue<pair<int,int>> pq;
        for(auto &i: subTree[src]) pq.push(i);
        
        int indexMax = -1;
        int val = 0;
        int val2nd = 0;
        if(pq.size()){
            indexMax = pq.top().second;
            val = pq.top().first;
            pq.pop();
            if(pq.size()){
                val2nd = pq.top().first;
            }
        }
        
        for(auto &i: adj[src]){
            
            if(vis[i]) continue;
            int currAns = 0;
            
            if(i == indexMax) currAns += val2nd;
            else currAns += val;
            
            int addOn = (src%2 == 0 ? 2 : 1);
            ans[i] = max({ans[i], currAns + addOn, topsAns + addOn});
            f2(i, vis, adj, subTree, ans, max(currAns + addOn, topsAns + addOn));
        }
        return;
    }
    
    vector<int> timeTaken(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> adj[n+1];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> ans(n+1, 0);
        vector<int> vis(n+1, 0);
        vector<vector<pair<int,int>>> subTree(n+1);
        f(0, vis, adj, subTree, ans);        
        vector<int> vis2(n+1, 0);
        f2(0, vis2, adj, subTree, ans, 0);
        return ans;
        
    }
};