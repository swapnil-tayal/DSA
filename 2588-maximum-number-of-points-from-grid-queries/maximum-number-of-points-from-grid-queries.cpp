class Solution {
    int n;
    int m;
    int k;
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
        k = queries.size();
        n = grid.size();
        m = grid[0].size();
        vector<int> ans(k, 0);
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int row[] = {0,-1,0,1};
        int col[] = {1,0,-1,0};

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for(int i=0; i<k; i++){
            pq.push({ queries[i], i });
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> q;
        q.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        int cnt = 0;

        while(!pq.empty()){

            int val = pq.top().first;
            int ind = pq.top().second;
            pq.pop();

            while(!q.empty() and q.top().first < val){
                
                int val = q.top().first;
                int x = q.top().second.first;   
                int y = q.top().second.second;
                q.pop();
                cnt++;

                for(int i=0; i<4; i++){
                    int newx = row[i]+x;
                    int newy = col[i]+y;
                    if(newx >= 0 and newy >= 0 and newx < n and newy < m and vis[newx][newy] == 0){
                        q.push({ grid[newx][newy], {newx, newy} });
                        vis[newx][newy] = 1;
                    }
                }
            }
            ans[ind] = cnt;
        }
        return ans;
    }
};