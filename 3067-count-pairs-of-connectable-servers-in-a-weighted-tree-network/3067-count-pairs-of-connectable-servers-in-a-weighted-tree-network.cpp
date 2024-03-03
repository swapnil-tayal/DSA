class Solution {
    int signalSpeed;
public:
    
    int f(int src, int tar, vector<pair<int,int>> adj[], int cnt, vector<int> &vis){
        
        vis[src] = 1;
        int num = 0;
        vector<int> arr;
        for(auto &i: adj[src]){
            
            if(vis[i.first]) continue;
            int x = f(i.first, tar, adj, cnt+i.second, vis);
            
            if(tar == src) arr.push_back(x);
            else num += x;
        }
        
        if(tar == src){
            int m = arr.size();
            int sum = arr[m-1];
            int x = 0;
            for(int k=m-2; k>=0; k--){
                x += sum * arr[k];
                sum += arr[k];
            }
            return x;
        }else{
            if(cnt != 0 and cnt%signalSpeed == 0) return num+1;
            return num;
        }
    }
    
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        
        this->signalSpeed = signalSpeed;
        int n = edges.size()+1;
        vector<pair<int,int>> adj[n];
        for(auto &i: edges){
            adj[i[0]].push_back({ i[1], i[2] });
            adj[i[1]].push_back({ i[0], i[2] });
        }
        
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            
            vector<int> vis(n, 0);
            ans[i] = f(i, i, adj, 0, vis);
        }
        return ans;
    }
};