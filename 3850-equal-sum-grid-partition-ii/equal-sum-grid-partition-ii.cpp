class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        long long sum = 0;
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<long long,vector<int>> mpH, mpV;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                mpH[grid[i][j]].push_back(i);
                mpV[grid[i][j]].push_back(j);
                sum += grid[i][j];
            }
        }
        
        long long currSum = 0;
        for(int i=0; i<n-1; i++){

            for(int j=0; j<m; j++){
                currSum += grid[i][j];
            }

            long long diff = sum - currSum;
            if(diff == currSum) return true;
            if(diff > currSum){
                long long num = diff - currSum;
                int ind = upper_bound(mpH[num].begin(), mpH[num].end(), i) - mpH[num].begin();
                if(ind != mpH[num].size()){
                    if(m == 1){
                        if(grid[i+1][0] == num || grid[n-1][0] == num) return true;
                    }else{
                        if(i == n-2) {
                            if(grid[n-1][0] == num || grid[n-1][m-1] == num) return true;
                        }else return true;
                    }
                }
            
            }else{
                long long num = currSum - diff;
                if(mpH[num].size() == 0) continue;
                int ind = mpH[num][0];
                if(ind <= i){
                    if(m == 1){
                        if (grid[i][0] == num || grid[0][0] == num) return true;
                    }else{
                        if(i == 0){
                            if(grid[0][0] == num || grid[0][m-1] == num) return true;
                        } else return true;
                    }
                }
            }
        }

        currSum = 0;
        for(int j=0; j<m-1; j++){

            for(int i=0; i<n; i++){
                currSum += grid[i][j];
            }
            long long diff = sum - currSum;
            if(diff == currSum) return true;
            if(diff > currSum){
                long long num = diff - currSum;
                int ind = upper_bound(mpV[num].begin(), mpV[num].end(), j) - mpV[num].begin();
                if(ind != mpV[num].size()){
                    if(n == 1){
                        if(grid[0][j+1] == num || grid[0][m-1] == num) return true;
                    }else{
                        if(j == m-2){
                            if(grid[0][m-1] == num || grid[n-1][m-1] == num) return true;
                        }else return true;
                    }
                }
            
            }else{
                long long num = currSum - diff;
                if(mpV[num].size() == 0) continue;
                int ind = mpV[num][0];
                if(ind <= j){
                    if(n == 1){
                        if (grid[0][j] == num || grid[0][0] == num) return true;
                    }else{
                        if(j == 0){
                            if(grid[0][0] == num || grid[n-1][0] == num) return true;
                        } else return true;
                    }
                }
            }
        }
        return false;
    }
};