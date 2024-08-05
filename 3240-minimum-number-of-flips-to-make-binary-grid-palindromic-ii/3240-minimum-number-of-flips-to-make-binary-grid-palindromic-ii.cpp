class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int ones = 0;
        int pair2 = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                set<pair<int,int>> st;
                st.insert({ i, j });
                st.insert({ n-i-1, j });
                st.insert({ n-i-1, m-j-1 });
                st.insert({ i, m-j-1 });
                
                int cnt1 = 0;
                int cnt0 = 0;
                for(auto [x, y]: st){
                    cnt1 += grid[x][y] == 1;
                    cnt0 += grid[x][y] == 0;
                }
                
                if(st.size() == 2){
                    if(cnt1 == cnt0) pair2++;    
                }
                
                if(cnt1 == cnt0){
                    ans += cnt1;
                    for(auto [x, y]: st){
                        if(grid[x][y] == 1) grid[x][y] = 0; 
                    }
                }
                else if(cnt1 > cnt0){
                    ans += cnt0;
                    for(auto [x, y]: st){
                        if(grid[x][y] == 0) grid[x][y] = 1; 
                    }
                }else{
                    ans += cnt1;
                    for(auto [x, y]: st){
                        if(grid[x][y] == 1) grid[x][y] = 0; 
                    }
                }
            }
        }
        int cntones = 0;
        for(auto i: grid){
            for(auto j: i){
                cntones += (j==1);
            }
        }
        if(cntones % 2 == 1){
            cntones -= 1;
            ans++;
        }
        if(cntones > 0 && cntones%2 == 0 and cntones%4 != 0){
            if(pair2 == 0) ans += 2;
            cntones -= 2;
        }
        return ans;
    }
};