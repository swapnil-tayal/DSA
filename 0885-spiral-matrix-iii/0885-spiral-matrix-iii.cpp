class Solution {
public:

    int check(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j] == 1) return 0;
            }
        }
        return 1;
    }
    
    void f(int i, int j, string dir, vector<vector<int>> &grid, vector<vector<int>> &ans){
        
        if(check(grid)) return;
        
        
        int n = grid.size();
        int m = grid[0].size();
        if(i != n-1 && i != 0 && j != m-1 && j != 0){
            // cout<<i<<' '<<j<<'\n';
            grid[i][j] = 2;
            ans.push_back({ i-1, j-1 });
        }
        // cout<<i<<' '<<j<<' '<<dir<<'\n';
        
        if(dir == "left"){
            
            if(grid[i+1][j] == 1) f(i+1, j, "down", grid, ans);
            else f(i, j+1, "left", grid, ans);
        
        }else if(dir == "down"){
            
            if(grid[i][j-1] == 1) f(i, j-1, "right", grid, ans);
            else f(i+1, j, "down", grid, ans);
        
        }else if(dir == "right"){
                        
//             if(i == 3 and j == 5){
//                 for(auto i: grid){
//                     for(auto j: i) cout<<j<<' ';
//                     cout<<'\n';
//                 }
//             }
            
            if(grid[i-1][j] == 1) f(i-1, j, "up", grid, ans);
            else f(i, j-1, "right", grid, ans);
            
        }else{
            if(grid[i][j+1] == 1) f(i, j+1, "left", grid, ans);
            else f(i-1, j, "up", grid, ans);
            
        }
        return;
    }
    
    vector<vector<int>> spiralMatrixIII(int n, int m, int rStart, int cStart) {
        
        vector<vector<int>> grid(n+2, vector<int>(m+2, 1));
        
        n = grid.size();
        m = grid[0].size();
        // for(auto i: grid){
        //     for(auto j: i){
        //         cout<<j<<' ';
        //     }
        //     cout<<'\n';
        // }
        // cout<<'\n';
        vector<vector<int>> ans;
        ans.push_back({ rStart, cStart });
        grid[rStart+1][cStart+1] = 2;
        f(rStart+1, cStart+2, "left", grid, ans);
        
        return ans;
    }
};