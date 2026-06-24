class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
  
        vector<vector<int>> mat(n, vector<int>(n, 1e8));
        for(auto &i: edges){
            mat[i[0]][i[1]] = i[2];
            mat[i[1]][i[0]] = i[2];
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i == j || mat[i][k] == 1e8 || mat[k][j] == 1e8) continue;
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        int ans = -1;
        int minCnt = 1e9;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(mat[i][j] <= distanceThreshold) cnt++;
            }
            if(minCnt >= cnt){
                ans = i;
                minCnt = cnt;
            }
        }
        return ans;
    }
};