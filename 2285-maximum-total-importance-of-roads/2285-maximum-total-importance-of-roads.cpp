class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<long long> inD(n, 0);
        
        for(auto i: roads){
            inD[i[0]]++;
            inD[i[1]]++;
        }
        
        
        sort(inD.begin(), inD.end());
        
        long long ans = 0;
        for(long long i=0; i<n; i++){
            ans += inD[i]*(i+1);
        }
        
        return ans;
    }
};