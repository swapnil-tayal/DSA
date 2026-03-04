class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int cnt = 0;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(mat[i][j] == 1){
                    
                    int f = 0;
                    for(int k=0; k<n; k++){
                        if(k == i) continue;
                        if(mat[k][j] == 1) f = 1;
                    }
                    for(int k=0; k<m; k++){
                        if(k == j) continue;
                        if(mat[i][k] == 1) f = 1;
                    }
                    if(f == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};