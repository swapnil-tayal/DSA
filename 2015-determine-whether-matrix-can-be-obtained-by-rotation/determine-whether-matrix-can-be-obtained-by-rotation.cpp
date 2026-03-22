class Solution {
public:

    void f(vector<vector<int>> &grid){

        int n = grid.size();
        for(int i=0; i<n/2; i++){
            for(int j=i; j<n-i-1; j++){

                int temp = grid[i][j];
                grid[i][j] = grid[n-j-1][i];
                grid[n-j-1][i] = grid[n-i-1][n-j-1];
                grid[n-i-1][n-j-1] = grid[j][n-i-1];
                grid[j][n-i-1] = temp;
            }
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int n = mat.size();
        int cnt = 0;
        while(cnt < 4){
            if(mat == target) return 1;
            f(mat);
            cnt++;
        }
        return 0;
    }
};