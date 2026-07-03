class Solution {
public:

    int f(long long mid, vector<pair<int,long long>> adj[], int n, long long k){

        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({ 0, 0 });

        while(!pq.empty()){

            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(cost > dis[node]) continue;

            for(auto &i: adj[node]){
                if(dis[i.first] > i.second + cost and i.second >= mid and i.second + cost <= k){
                    dis[i.first] = i.second + cost;
                    pq.push({ dis[i.first], i.first });
                }
            }
        }
        return dis[n-1] != LLONG_MAX;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        
        int n = online.size();
        vector<pair<int,long long>> adj[n];
        long long s = INT_MAX;
        long long e = 0;
        for(auto &i: edges){
            if(online[i[0]] and online[i[1]] and i[2] <= k){
                adj[i[0]].push_back({ i[1], i[2] });
                s = min(s, (long long)i[2]);
                e = max(e, (long long)i[2]);
            }
        }

        int ans = -1;
        while(s <= e){
            long long mid = s + (e-s)/2;
            if(f(mid, adj, n, k)){
                ans = mid;
                s = mid+1;
            }else e = mid-1;
        }
        return ans;
    }
};