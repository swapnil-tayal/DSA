class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        int row[] = {1,-1,1,-1,0,0,1,-1};
        int col[] = {1,-1,-1,1,1,-1,0,0};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                int val = img[i][j];
                int cnt = 1;
                for(int k=0; k<8; k++){
                    
                    int newi = i + row[k];
                    int newj = j + col[k];
                    if(newi >= 0 and newj >= 0 and newi < n and newj < m){
                        
                        
                        val += img[newi][newj];
                        cnt++;
                    }
                }
                ans[i][j] = val/cnt;
            }
        }
        return ans;
    }
};