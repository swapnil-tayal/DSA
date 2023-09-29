//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int n,m;
  public:
  
    void bfs(int i, int j, vector<vector<int>> &grid){
        
        queue<pair<int,int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        
        
        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, -1, 1};
        
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                
                int newx = x + row[i];
                int newy = y + col[i];
                
                if(newx >= 0 and newy >= 0 and newx < n and newy < m and grid[newx][newy] == 1){
                    
                    grid[newx][newy] = 0;
                    q.push({newx, newy});
                }
            }
        }
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        n = grid.size();
        m = grid[0].size();
        
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1){
                // cout<<i<<' '<<0<<' ';
                bfs(i, 0, grid);
            }if(grid[i][m-1] == 1){
                bfs(i, m-1, grid);
            }
        }
        
        // for(auto &i: grid){
        //     for(auto &j: i) cout<<j;
        //     cout<<'\n';
        // }
        
        for(int i=0; i<m; i++){
            if(grid[0][i] == 1){
                bfs(0, i, grid);
            }if(grid[n-1][i] == 1){
                bfs(n-1, i, grid);
            }
        }
        int cnt = 0;
        for(auto &i: grid){
            for(auto &j: i) cnt += j;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends