class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        time.insert(time.begin(), 0);
        vector<int> inD(n+1, 0);
        vector<int> adj[n+1];
        vector<int> dist(n+1, 0);
        
        int maxi = 0;
        for(auto i: time){
            maxi = max(maxi, i);
        }
        
        for(int i=1; i<n; i++){
            dist[i] = time[i];
        }
        
        for(int i=0; i<relations.size(); i++){
            inD[relations[i][1]]++;
            adj[relations[i][0]].push_back(relations[i][1]);
        }
        // for(auto i: inD) cout<<i<<' ';
        
        queue<pair<int,int>> q;
        for(int i=1; i<=n; i++){
            if(inD[i] == 0){
                q.push({i, time[i]});
            }
        }
        
        int cnt = 0;
        // cout<<q.size()<<' ';    
        while(!q.empty()){
            
            int node = q.front().first;
            int val = q.front().second;
            q.pop();
            
            for(auto i: adj[node]){
                
                inD[i]--;
                dist[i] = max(dist[i], val + time[i]);
                if(inD[i] == 0){
                    q.push({i, dist[i]});
                }
            }
        }
        
        // for(auto i: dist) cout<<i<<' ';
        
        for(int i: dist){
            maxi = max(i, maxi);
        }
        return maxi;
    }
};