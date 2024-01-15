class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<int> inD(100001, -1);
        int n = matches.size();
        
        for(int i=0; i<n; i++){
            
            if(inD[matches[i][1]] == -1) inD[matches[i][1]] = 1;
            else inD[matches[i][1]]++;
            
            // if(outD[matches[i][0]] == -1) outD[matches[i][0]] = 1;
            // else outD[matches[i][0]]++;
            
            if(inD[matches[i][0]] == -1) inD[matches[i][0]] = 0;
            // if(outD[matches[i][1]] == -1) outD[matches[i][1]] = 0;
        }
        vector<vector<int>> ans(2);
        for(int i=0; i<100001; i++){
            
            if(inD[i] != -1){
                if(inD[i] == 1) ans[1].push_back(i);
                else if(inD[i] == 0) ans[0].push_back(i);
            }
        }
        return ans;
    }
};