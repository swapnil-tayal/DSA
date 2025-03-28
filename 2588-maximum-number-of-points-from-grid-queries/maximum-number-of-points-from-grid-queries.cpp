class Solution {
    int n;
    int m;
    int k;
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
        k = queries.size();
        n = grid.size();
        m = grid[0].size();

        // cout<<n<<" "<<m<<" "<<k<<'\n';
        // return {};
        int row[] = {0,-1,0,1};
        int col[] = {1,0,-1,0};
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for(int i=0; i<k; i++){
            pq.push({ queries[i], i });
        }
        vector<int> ans(k, 0);

        deque<pair<int,int>> dq;
        dq.push_front({0, 0});
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;
        map<int,int> mp;

        while(!pq.empty()){

            int val = pq.top().first;
            int ind = pq.top().second;
            pq.pop();

            if(mp.count(val)){
                ans[ind] = mp[val];
                continue;
            }

            int g = dq.size();
            queue<pair<int,int>> q;

            while(g--){
                int x = dq.front().first;
                int y = dq.front().second;
                if(vis[x][y]) dq.pop_front();
                else if(grid[x][y] < val){
                    q.push({x, y});
                    vis[x][y] = 1;
                    dq.pop_front();
                }else{
                    auto d = dq.front();
                    dq.push_back(d);
                    dq.pop_front();
                }
            }
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                cnt++;
                q.pop();

                for(int i=0; i<4; i++){

                    int newx = row[i]+x;
                    int newy = col[i]+y;
                    if(newx >= 0 and newy >= 0 and newx < n and newy < m and vis[newx][newy] == 0){
                        
                        if(grid[newx][newy] < val){
                            vis[newx][newy] = 1;
                            q.push({ newx, newy });
                        }else{
                            dq.push_front({newx, newy});
                        }
                    }
                }
            }
            mp[val] = cnt;
            ans[ind] = cnt;
        }
        return ans;
    }
};