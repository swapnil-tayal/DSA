class Solution {
public:

    int f(vector<vector<int>> &grid, int val){

        int n = grid.size();
        queue<pair<int,int>> q;
        if(grid[0][0] < val) return false;
        q.push({ 0, 0 });
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;

        int row[] = {-1,1,0,0};
        int col[] = {0,0,-1,1};

        while(!q.empty()){

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == n-1 and y == n-1) return true;

            for(int k=0; k<4; k++){

                int newx = x + row[k];
                int newy = y + col[k];
                if(newx >= 0 and newy >= 0 and newx < n and newy < n and vis[newx][newy] == 0 and grid[newx][newy] >= val){
                    vis[newx][newy] = 1;
                    q.push({ newx, newy });
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<vector<int>> q;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({ 0, i, j });
                    dis[i][j] = 0;
                }
            }
        }

        int row[] = {-1,1,0,0};
        int col[] = {0,0,-1,1};

        while(!q.empty()){

            int d = q.front()[0];
            int x = q.front()[1];
            int y = q.front()[2];
            q.pop();

            for(int k=0; k<4; k++){

                int newx = x + row[k];
                int newy = y + col[k];
                if(newx >= 0 and newy >= 0 and newx < n and newy < n){
                    if(dis[newx][newy] > d + 1){
                        dis[newx][newy] = d+1;
                        q.push({ d+1, newx, newy });
                    }
                }
            }
        }

        // for(auto i: dis){
        //     for(auto j: i) cout<<j<<' ';
        //     cout<<'\n';
        // }

        int s = 0;
        int e = n+n;
        int ans = e;

        while(s <= e){

            int mid = (s+e)/2;
            if(f(dis, mid)){
                s = mid+1;
                ans = mid;
            }
            else e = mid-1;
        }
        return ans;
    }
};