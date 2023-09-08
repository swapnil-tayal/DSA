class Solution {
public:
    
    void solve(int i, int n, vector<vector<int>> &ans){
        
        if(i == n+1) return;
        
        vector<int> temp;
        if(i == 1) temp.push_back(1);
        else{
            
            vector<int> temp2 = ans.back();
            for(int j=0; j<i; j++){
                
                int sum = 0;
                if(temp2.size() > j) sum += temp2[j];
                if(j-1 >= 0) sum += temp2[j-1];
                temp.push_back(sum);
            }
        }
        ans.push_back(temp);
        solve(i+1, n, ans);
    }
    
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        solve(1, numRows, ans);
        return ans;
        // 1
        // 11
        // 121
        // 1331
        // 14641
    }
};