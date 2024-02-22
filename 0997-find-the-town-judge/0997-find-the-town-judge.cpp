class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> inD(n+1, 0), outD(n+1, 0);
        int m = trust.size();
        
        for(auto &i: trust){
            
            int v = i[0];
            int u = i[1];
            inD[u]++;
            outD[v]++;
        }
        for(int i=1; i<=n; i++){
            if(inD[i] == n-1 and outD[i] == 0) return i;
        }
        return -1;
    }
};