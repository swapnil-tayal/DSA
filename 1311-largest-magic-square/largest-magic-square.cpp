class Solution {
public:

    int f(int x1, int y1, int x2, int y2, vector<vector<int>> &grid){

        int sum5 = 0;
        int sum6 = 0;
        for(int k = 0; k <= x2 - x1; k++) sum5 += grid[x1 + k][y1 + k];
        for(int k = 0; k <= x2 - x1; k++) sum6 += grid[x1 + k][y2 - k];
        for(int i=x1; i<=x2; i++){
            int sum = 0;
            for(int j=y1; j<=y2; j++){
                sum += grid[i][j];
            }
            if(sum != sum5) return 0;
        }
        for(int j=y1; j<=y2; j++){
            int sum = 0;
            for(int i=x1; i<=x2; i++){
                sum += grid[i][j];
            }
            if(sum != sum6) return 0;
        }
        return sum5 == sum6;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        cout<<n<<' '<<m<<'\n';
        int ans = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                for(int p=i+1; p<n; p++){
                    for(int q=j+1; q<m; q++){
                        
                        if(p-i == q-j){
                            if(f(i,j,p,q,grid)){
                                ans = max(ans, p-i+1);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};