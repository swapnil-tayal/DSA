class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size(); 
        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
            
                if(i == n-j-1) break;
                
                int newi = n-j-1;
                int newj = n-i-1;
                swap(matrix[i][j], matrix[newi][newj]);
            }
        }
    }
};