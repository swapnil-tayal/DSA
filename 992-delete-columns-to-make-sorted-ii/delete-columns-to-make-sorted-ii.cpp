class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        vector<string> a(n, "");

        for(int j=0; j<m; j++){

            vector<string> temp = a;
            for(int i=0; i<n; i++){
                temp[i] += strs[i][j];
            }
            int moveForw = 0;
            int deleteRow = 0;
            for(int i=1; i<n; i++){
                if(temp[i] < temp[i-1]){
                    moveForw = 1;
                    deleteRow = 1;
                    break;
                
                }else if(temp[i] == temp[i-1]){
                    moveForw = 1;
                }
            }
            if(moveForw == 0) break;
            else{
                if(deleteRow == 0) a = temp;
                else ans++;
            }
        }
        return ans;
    }
};