class Solution {
public:
    
    bool dfs(vector<vector<char>> &board, vector<vector<int>> &vis, string word, int ind, int i, int j){
        
        vis[i][j] = 1;
        int n = board.size();
        int m = board[0].size();
        
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, -1, 0, 1};
        
        for(int k=0; k<4; k++){
            
            int newi = i + row[k];
            int newj = j + col[k];
            
            if(newi >= 0 and newi < n and newj >= 0 and newj < m and board[newi][newj] == word[ind] and vis[newi][newj] == 0){
                
                if(ind == word.size()-1) return true;
                
                if( dfs(board, vis, word, ind+1, newi, newj) ){
                    return true;
                }
            }
        }
        vis[i][j] = 0;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(board[i][j] == word[0]){
                    
                    if(0 == word.size()-1) return true;
                
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    if(dfs(board, vis, word, 1, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};