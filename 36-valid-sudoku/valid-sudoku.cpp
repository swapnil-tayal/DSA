class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        
        vector<set<int>> row(9);
        vector<set<int>> col(9);
        vector<set<int>> block(9);
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                
                if(b[i][j] == '.') continue;
                
                int blki = (((i/3)*3) + (j/3));
                
                int num = b[i][j];
                
                if(row[i].count(num) || col[j].count(num) || block[blki].count(num)){
                    return false;
                }
                row[i].insert(num);
                col[j].insert(num);
                block[blki].insert(num);
            }
        }
        return true;
    }
};