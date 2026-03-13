class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        int ans = 0;

        for(int i=0; i<n; i++){

            int ind = 0;
            while(ind < m){
                char ch = board[i][ind];
                int cnt = 0;
                while(ind < m and board[i][ind] == ch){
                    ind++;
                    cnt++;
                }
                if(cnt > 1 and ch == 'X') ans++;
            }
        }        
        for(int j=0; j<m; j++){

            int ind = 0;
            while(ind < n){
                char ch = board[ind][j];
                int cnt = 0;
                while(ind < n and board[ind][j] == ch){
                    ind++;
                    cnt++;
                }
                if(cnt > 1 and ch == 'X') ans++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'X'){
                    int ch = 0;
                    if(i-1 >= 0 and board[i-1][j] != '.') ch++;
                    if(j-1 >= 0 and board[i][j-1] != '.') ch++;
                    if(i+1 < n and board[i+1][j] != '.') ch++;
                    if(j+1 < m and board[i][j+1] != '.') ch++;
                    if(ch == 0) ans++;
                }
            }
        }
        return ans;
    }
};