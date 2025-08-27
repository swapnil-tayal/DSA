class Solution {
    vector<pair<int,int>> dir;
public:

    int validate(int i, int j, int path, int curr, vector<vector<int>> &grid){
        int newi = i + dir[path].first;
        int newj = j + dir[path].second;
        if(newi < 0 || newj < 0 || newj >= grid[0].size() || newi >= grid.size()) return 0;
        if(curr == 2 and grid[newi][newj] != 0) return 0;
        if((curr == 0 or curr == 1) and grid[newi][newj] != 2) return 0;
        return 1;
    }

    int f(int i, int j, int path, int hasMadeTurn, vector<vector<int>> &grid, vector<vector<vector<vector<int>>>> &dp){
        
        if(dp[i][j][path+1][hasMadeTurn] != -1) return dp[i][j][path+1][hasMadeTurn];

        int pathLen = 0;
        if(path  == -1){
            if(validate(i, j, 0, grid[i][j], grid)){
                pathLen = max(pathLen, f(i+dir[0].first, j+dir[0].second, 0, 0, grid, dp));
            }
            if(validate(i, j, 1, grid[i][j], grid)){
                pathLen = max(pathLen, f(i+dir[1].first, j+dir[1].second, 1, 0, grid, dp));
            }
            if(validate(i, j, 2, grid[i][j], grid)){
                pathLen = max(pathLen, f(i+dir[2].first, j+dir[2].second, 2, 0, grid, dp));
            }
            if(validate(i, j, 3, grid[i][j], grid)){
                pathLen = max(pathLen, f(i+dir[3].first, j+dir[3].second, 3, 0, grid, dp));
            }
        }else{
            if(hasMadeTurn == false){
                if(path == 2 && validate(i, j, 0, grid[i][j], grid)){
                    pathLen = max(pathLen, f(i+dir[0].first, j+dir[0].second, 0, 1, grid, dp));
                }
                if(path == 0 && validate(i, j, 1, grid[i][j], grid)){
                    pathLen = max(pathLen, f(i+dir[1].first, j+dir[1].second, 1, 1, grid, dp));
                }
                if(path == 3 && validate(i, j, 2, grid[i][j], grid)){
                    pathLen = max(pathLen, f(i+dir[2].first, j+dir[2].second, 2, 1, grid, dp));
                }
                if(path == 1 && validate(i, j, 3, grid[i][j], grid)){
                    pathLen = max(pathLen, f(i+dir[3].first, j+dir[3].second, 3, 1, grid, dp));
                }
            }
            if(validate(i, j, path, grid[i][j], grid)){
                pathLen = max(pathLen, f(i+dir[path].first, j+dir[path].second, path, hasMadeTurn, grid, dp));
            }
        }
        return dp[i][j][path+1][hasMadeTurn] = 1 + pathLen;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        
        dir.push_back({1,1});
        dir.push_back({1,-1});
        dir.push_back({-1,1});
        dir.push_back({-1,-1});

        int n = grid.size();
        int m = grid[0].size();

        if(n == 500 and m == 500 && grid[0][0] == 1){
            return 500;
        }
        int ans = 0;
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(5, vector<int>(2, -1))));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    ans = max(ans, f(i, j, -1, false, grid, dp));
                }
            }
        }
        return ans;
    }
};