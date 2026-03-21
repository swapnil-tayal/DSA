class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        vector<vector<int>> a;
        for(int i=x; i<x+k; i++){
            vector<int> temp;
            for(int j=y; j<y+k; j++){
                temp.push_back(grid[i][j]);
            }
            a.push_back(temp);
        }
        reverse(a.begin(), a.end());
        for(int i=x; i<x+k; i++){
            for(int j=y; j<y+k; j++){
                grid[i][j] = a[i-x][j-y];
            }
        }
        return grid;
    }
};