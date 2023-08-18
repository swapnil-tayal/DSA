class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        int m = roads.size();
        vector<int> inD(n, 0);
        set<pair<int,int>> st;
        
        for(auto i: roads){
            inD[i[0]]++;
            inD[i[1]]++;
            
            pair<int,int> pr = { min(i[0], i[1]), max(i[0], i[1]) };
            st.insert(pr);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                pair<int,int> pr = { min(i, j), max(i, j) };
                if(st.count(pr)){
                    ans = max(inD[i]+inD[j]-1, ans);
                }else{
                    ans = max(inD[i]+inD[j], ans);
                }
            }
        }
        return ans;
    }
};