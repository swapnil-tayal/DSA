class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int mini = 1e9;
        long long sum = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cnt += matrix[i][j] < 0;
                mini = min(mini, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }
        if(cnt % 2 == 0) return sum;
        else return sum - abs(2*mini);
    }
};