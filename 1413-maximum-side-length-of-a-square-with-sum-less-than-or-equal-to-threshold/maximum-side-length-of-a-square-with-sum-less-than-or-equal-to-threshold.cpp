class Solution {
public:

    int f(int mid, vector<vector<int>> &mat, int k, vector<vector<int>> &prefixSum){

        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int newi = i+mid-1;
                int newj = j+mid-1;
                if(newi < n and newj < m){
                    int sum = prefixSum[newi][newj];
                    if(i-1 >= 0) sum -= prefixSum[i-1][newj];
                    if(j-1 >= 0) sum -= prefixSum[newi][j-1]; 
                    if(i-1 >= 0 and j-1 >= 0) sum += prefixSum[i-1][j-1];
                    if(sum <= k) return 1;
                }
            }
        }
        return 0;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                prefixSum[i][j] = mat[i][j];
                if(i-1 >= 0) prefixSum[i][j] += prefixSum[i-1][j];
                if(j-1 >= 0) prefixSum[i][j] += prefixSum[i][j-1];
                if(i-1 >= 0 and j-1 >= 0) prefixSum[i][j] -= prefixSum[i-1][j-1];
            }
        }
        int s = 1;
        int e = min(n, m);
        int ans = 0;
        while(s <= e){
            int mid = (s+e)/2;
            if(f(mid, mat, threshold, prefixSum)){
                ans = mid;
                s = mid+1;
            }else e = mid-1;
        }
        return ans;
    }
};