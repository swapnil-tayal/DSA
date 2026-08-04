class Solution {
public:

    bool check(int i, int j, string word, vector<vector<char>> &board){

        int n = board.size();
        int m = board[0].size();

        if(m-j < word.size()) return false;
        if(j+word.size() < m && board[i][j+word.size()] != '#') return false;

        int ind = 0;
        for(int p=j; p<j+word.size(); p++){
            if(board[i][p] == '#') return false;
            if(board[i][p] != ' ' and board[i][p] != word[ind]) return false;
            ind++;
        }
        return true;
    }

    bool check2(int i, int j, string word, vector<vector<char>> &board){

        int n = board.size();
        int m = board[0].size();

        if(n-i < word.size()) return false;
        if(i+word.size() < n && board[i+word.size()][j] != '#') return false;

        int ind = 0;
        for(int p=i; p<i+word.size(); p++){
            // cout<<p<<' '<<word[ind]<<'\n';
            if(board[p][j] == '#') return false;
            if(board[p][j] != ' ' and board[p][j] != word[ind]) return false;
            ind++;
        }
        return true;
    }

    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        string revWord = word;
        reverse(revWord.begin(), revWord.end());

        // cout<<check2(0, 2, word, board)<<'\n';

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] != '#' and (j-1 == -1 || board[i][j-1] == '#')){
                    if(check(i, j, word, board) || check(i, j, revWord, board)) return true;
                }
                if(board[i][j] != '#' and (i-1 == -1 || board[i-1][j] == '#')){
                    if(check2(i, j, word, board) || check2(i, j, revWord, board)) return true;
                }
            }
        }
        return false;
    }
};