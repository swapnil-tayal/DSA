class Solution {
public:
    
    void solve(int n, vector<int> &prev, vector<vector<int>> &res, int i){
        
        if(i == n+1){
            return;
        }
        
        vector<int> curr(i, 0);
        
        for(int index=0; index<i; index++){
            
            int x, y;
            x=0; y=0;
            
            if(index-1 >= 0) x = prev[index-1];
            if(index < prev.size()) y = prev[index];
            
            curr[index] = x+y;
            
        }
        res[i-1] = curr;
        solve(n, curr, res, i+1);
        return;
        
    }
    
    vector<int> getRow(int rowIndex) {
        
        vector<int> prev(1, 1);
        vector<vector<int>> res(rowIndex+1);
        res[0] = prev;
        
        solve(rowIndex+1, prev, res, 2);
        return res[rowIndex];
    }
};