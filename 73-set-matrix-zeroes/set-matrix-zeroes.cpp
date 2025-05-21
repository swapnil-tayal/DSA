class Solution {
public:
    
    void dfs(int a, int b, vector<vector<int>> &matrix){
        
        int x=a;
        int y=b;
        int n = matrix.size();
        int m = matrix[0].size();
        
        while(a >= 0){
            matrix[a][b] = 0;
            a--;
        }
        a = x; b = y;
        while(a < n){
            matrix[a][b] = 0;
            a++;
        }
        a = x; b = y;
        while(b >= 0){
            matrix[a][b] = 0;
            b--;
        }
        a = x; b = y;
        while(b < m){
            matrix[a][b] = 0;
            b++;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<pair<int, int>> arr;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(matrix[i][j] == 0) arr.push_back({i, j});
            }
        }
        
        n = arr.size();
        for(int i=0; i<n; i++){
            int a = arr[i].first;
            int b = arr[i].second;
            dfs(a, b, matrix);
        }
        
    }
};