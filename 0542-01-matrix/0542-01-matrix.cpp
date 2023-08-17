class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        queue<vector<int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(mat[i][j] == 0) q.push({ i, j, 0 });
                else mat[i][j] = 1e9;
            }
        }
        
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, -1, 0, 1};
        
        while(!q.empty()){
            
            int i = q.front()[0];
            int j = q.front()[1];
            int dist = q.front()[2];
            
            // cout<<i<<' '<<j<<'\n';
            q.pop();
            
            for(int k=0; k<4; k++){
                
                int newi = i + row[k];
                int newj = j + col[k];
                
                if(newi >= 0 and newj >=0 and newi < n and newj < m){
                    
                    if(mat[newi][newj] > 1 + dist){
                        mat[newi][newj] = 1 + dist;
                        q.push({ newi, newj, dist+1 });
                    }
                }
            }
        }
        return mat;
    }
};