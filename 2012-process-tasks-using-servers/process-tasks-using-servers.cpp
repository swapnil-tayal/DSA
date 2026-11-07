#define ll long long

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        auto cmp1 = [](vector<ll>& a, vector<ll>& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] > b[0];
        };

        auto cmp2 = [](vector<ll>& a, vector<ll>& b) {
            if(a[0] == b[0]){
                if(a[1] == b[1]) return a[2] > b[2];
                return a[1] > b[1];
            }
            return a[0] > b[0];
        };

        priority_queue<vector<ll>, vector<vector<ll>>, decltype(cmp1)> pq1(cmp1);
        priority_queue<vector<ll>, vector<vector<ll>>, decltype(cmp2)> pq2(cmp2);
        
        int n = servers.size();
        int m = tasks.size();

        for(int i=0; i<n; i++){
            pq1.push({ servers[i], i });
        }

        ll time = 0;
        vector<int> ans(m, 0);
        for(ll j=0; j<m; j++){
        
            time = max(time, j);
            while(!pq2.empty() && pq2.top()[0] <= time){
                auto x = pq2.top();
                pq2.pop();
                pq1.push({ x[1], x[2] });
            }

            if(pq1.size() == 0){
                time = pq2.top()[0];
                auto x = pq2.top();
                pq2.pop();
                pq1.push({ x[1], x[2] });
            }

            int weight = pq1.top()[0];
            int server = pq1.top()[1];
            pq1.pop();
            ans[j] = server;
            pq2.push({ time + tasks[j], weight, server });    
        }
        return ans;
    }
};