class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        long long totalSum = 0;
        for(auto i: grid){
            for(auto j: i) totalSum += j;
        }
        if(totalSum % 2 == 1) return false;
        long long sumH = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sumH += grid[i][j];
            }
            if(totalSum / 2 == sumH) return true;
        }
        long long sumV = 0;
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                sumV += grid[i][j];
            }
            if(totalSum / 2 == sumV) return true;
        }
        return false;
    }
};