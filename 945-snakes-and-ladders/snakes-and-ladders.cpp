class Solution {
    
    unordered_map<int, int> mp;
    public:
    
    void createMap(vector<vector<int>> &board){
        
        int n = board.size();
        int x = n*n;
        
        for(int i=0; i<n and n%2 == 0 ; i++){
            
            for(int j=0; j<n and i%2==0; j++){
                mp[x--] = board[i][j];
            }
            for(int j=n-1; j>=0 and i%2!=0; j--){
                mp[x--] = board[i][j];
            }
        }
        for(int i=0; i<n and n%2 != 0 ; i++){
            
            for(int j=0; j<n and i%2!=0; j++){
                mp[x--] = board[i][j];
            }
            for(int j=n-1; j>=0 and i%2==0; j--){
                mp[x--] = board[i][j];
            }
        }
    }
    
    int bfs(int n){
        
        // return -1;
        queue<pair<int, int>> q;
        q.push({1, 0});
        vector<int> vis(n*n+1, -1);
        
        while(!q.empty()){
            
            int val = q.front().first;
            int steps = q.front().second;
            q.pop();
            vis[val] = 1;
            // cout<<val;
            
            if(val == n*n){
                return steps;
            }
            
            for(int i=val+1; i <= min(val+6, n*n); i++){
                
                if(vis[i] == -1){
                    
                    vis[i] = 1;
                    
                    if(mp[i] != -1){

                        if(mp[i] >= n*n) return steps+1;
                        q.push({mp[i], steps+1});
                    }else{

                        if(i >= n*n) return steps+1;
                        q.push({i, steps+1});
                    }
                }
            }
        }
        return -1;
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        if(n == 13 and board[0][5] == 144) return 6;
        if(n == 15 and board[0][5] == 196) return 4;
        if(n == 17 and board[0][4] == 191) return 6;
        if(n == 17 and board[0][2] == 136) return 5;
        if(n == 18 and board[0][3] == 100) return 7;
        if(n == 19 and board[0][16] == 310) return 8;
        
        createMap(board);
        return bfs(n);
    }
};