#define pq_Min_Max pair<priority_queue<long long, vector<long long>, greater<long long>>, priority_queue<long long>>
#define pq_Max priority_queue<long long, vector<long long>, greater<long long>>
#define pq_Min priority_queue<long long>

class Solution {
    vector<long long> ans;
public:
    
    long long maxProduct(pq_Max &currMax, pq_Min &currMin){
        
        vector<long long> arr;
        while(currMax.size()){
            arr.push_back(currMax.top());
            currMax.pop();
        }
        int k = arr.size();
        while(currMin.size()){
            arr.insert(arr.begin()+k, currMin.top());
            currMin.pop();
        }
        for(auto &i: arr){
            if(i > 0) currMax.push(i);
            else currMin.push(i);
        }
        int n = arr.size();
        long long ans = 0;
        for(int i=0; i<n-2; i++){
            ans = max(ans, arr[i] * arr[i+1] * arr[i+2]);
        }
        return ans;
    }
    
    pq_Min_Max f(int src, vector<int> &vis, vector<int> adj[], vector<int> &cost){
        
        vis[src] = 1;
        pq_Max currMax;
        pq_Min currMin;
        if(cost[src] > 0) currMax.push(cost[src]);
        else currMin.push(cost[src]);
        
        for(auto i: adj[src]){
            
            if(vis[i]) continue;
            pq_Min_Max x = f(i, vis, adj, cost);
            while(x.first.size()){
                currMax.push(x.first.top());
                x.first.pop();
                if(currMax.size() > 3) currMax.pop();
            }
            while(x.second.size()){
                currMin.push(x.second.top());
                x.second.pop();
                if(currMin.size() > 3) currMin.pop();
            }
        }
        if(currMax.size() + currMin.size() < 3) ans[src] = 1;
        else ans[src] = maxProduct(currMax, currMin);
        return { currMax, currMin };
    }
    
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost){
        
        int n = cost.size();
        vector<int> adj[n];
        ans.resize(n, 0);
        
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n, 0);
        f(0, vis, adj, cost);
        return ans;
    }
};