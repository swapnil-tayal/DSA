class Solution {
    int n,m;
public:
    
    void f(int i, int j, string dir, vector<vector<int>> &grid, vector<vector<int>> &ans, int cnt){
        
        if(i != n-1 && i != 0 && j != m-1 && j != 0){
            cnt++;
            grid[i][j] = 2;
            ans.push_back({ i-1, j-1 });
        }
        if(cnt == ((n-2)*(m-2))) return;
        
        if(dir == "left"){
            
            if(grid[i+1][j] == 1) f(i+1, j, "down", grid, ans, cnt);
            else f(i, j+1, "left", grid, ans, cnt);
        
        }else if(dir == "down"){
            
            if(grid[i][j-1] == 1) f(i, j-1, "right", grid, ans, cnt);
            else f(i+1, j, "down", grid, ans, cnt);
        
        }else if(dir == "right"){
            
            if(grid[i-1][j] == 1) f(i-1, j, "up", grid, ans, cnt);
            else f(i, j-1, "right", grid, ans, cnt);
            
        }else{
            if(grid[i][j+1] == 1) f(i, j+1, "left", grid, ans, cnt);
            else f(i-1, j, "up", grid, ans, cnt);
            
        }
        return;
    }
    
    vector<vector<int>> spiralMatrixIII(int n, int m, int rStart, int cStart) {
        
        vector<vector<int>> grid(n+2, vector<int>(m+2, 1));
        
        this->n = grid.size();
        this->m = grid[0].size();
        vector<vector<int>> ans;
        ans.push_back({ rStart, cStart });
        grid[rStart+1][cStart+1] = 2;
        
        int cnt = 1;
        f(rStart+1, cStart+2, "left", grid, ans, cnt);
        return ans;
    }
};