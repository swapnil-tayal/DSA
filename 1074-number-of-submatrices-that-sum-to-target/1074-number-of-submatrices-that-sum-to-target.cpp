class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pre(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                int sum = 0;
                if(i-1 >= 0) sum += pre[i-1][j];
                if(j-1 >= 0) sum += pre[i][j-1];
                if(i-1 >= 0 and j-1 >= 0) sum -= pre[i-1][j-1];
                pre[i][j] = sum + matrix[i][j];
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                for(int x=i; x<n; x++){
                    for(int y=j; y<m; y++){
                        
                        int sum = pre[x][y];
                        if(i-1 >= 0) sum -= pre[i-1][y];
                        if(j-1 >= 0) sum -= pre[x][j-1];
                        if(i-1 >= 0 and j-1 >= 0) sum += pre[i-1][j-1];
                        cnt += sum == target;
                    }
                }
            }
        }
        return cnt;
        return 0;   
    }
};