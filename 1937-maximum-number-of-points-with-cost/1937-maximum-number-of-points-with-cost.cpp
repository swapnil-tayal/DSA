class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int m = points[0].size();
        
        vector<long long> prevRow(m, 0);
        for(int i=0; i<m; i++) prevRow[i] = points[0][i]; 
        
        for(int i=0; i<n-1; i++){
            
            vector<long long> leftToRight(m, 0);
            vector<long long> rightToLeft(m, 0);
            vector<long long> currRow(m, 0);
            
            leftToRight[0] = prevRow[0];
            for(int j=1; j<m; j++){
                leftToRight[j] = max(leftToRight[j-1]-1, prevRow[j]);
            }
            
            rightToLeft[m-1] = prevRow[m-1];
            for(int j=m-2; j>=0; j--){
                rightToLeft[j] = max(rightToLeft[j+1]-1, prevRow[j]);
            }
            
            for(int j=0; j<m; j++){
                currRow[j] = points[i+1][j] + max(leftToRight[j], rightToLeft[j]);
            }
            prevRow = currRow;
        }
        long long sum = 0ll;
        for(auto &i: prevRow) sum = max(sum, i);
        return sum;
    }
};