class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<int> pqq;

        for(int i=0; i<n; i++){
            priority_queue<int> pq; 
            for(int j=0; j<m; j++){
                pq.push(grid[i][j]);
            }
            while(pq.size() and limits[i]--){
                pqq.push(pq.top());
                pq.pop();
            }
        }
        long long sum = 0;
        while(pqq.size() and k--){
            sum += pqq.top();
            pqq.pop();
        }    
        return sum;
    }
};