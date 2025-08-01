class Solution {
public:
    
    void f(int i, int n, vector<vector<int>> &numsRows){
        
        if(i == n) return;
        
        if(i == 0){
            numsRows.push_back({1});
            
        }else{
            
            vector<int> temp = numsRows.back();
            vector<int> newArr(i+1, 0);
            for(int k=0; k<=i; k++){
                int val = 0;
                if(k-1 >= 0) val = temp[k-1];
                if(k < temp.size()) val += temp[k];
                newArr[k] = val;
            }
            numsRows.push_back(newArr);
        }
        f(i+1, n, numsRows);
    }
    
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> arr;
        f(0, numRows, arr);
        return arr;
    }
};