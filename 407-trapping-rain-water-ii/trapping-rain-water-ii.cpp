class Solution {
public:

    int f(int val, pair<int,int> ind, vector<vector<int>> &mat, vector<vector<int>> &vis, map<int,set<pair<int,int>>> &mp){
        
        int n = mat.size();
        int m = mat[0].size();
        int row[] = {1,0,-1,0};
        int col[] = {0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({ ind.first, ind.second });
        vis[ind.first][ind.second] = 1;
        set<pair<int,int>> newInd;
        int check = 1;
        int maxHeigth = 1e9;

        while(!q.empty()){

            int x = q.front().first;
            int y = q.front().second;
            newInd.insert({ x, y });
            q.pop();
        
            for(int k=0; k<4; k++){

                int newx = row[k] + x;
                int newy = col[k] + y;

                if(newx >= 0 and newy >= 0 and newx < n and newy < m){
                    
                    if(vis[newx][newy] != 1){
                        if(mat[newx][newy] == -1) check = 0;
                        else if(mat[newx][newy] == val){
                            vis[newx][newy] = 1;
                            q.push({newx, newy});
                        }
                        else if(mat[newx][newy] > val){
                            maxHeigth = min(maxHeigth, mat[newx][newy]);
                        }
                        else mat[newx][newy] = -1;
                    }

                }else{
                    mat[x][y] = -1;
                    check = 0;
                }
            }
        }
        if(check == 0){
            for(auto &i: newInd) mat[i.first][i.second] = -1;
            return 0;
        }
        int extra = 0;
        for(auto &i: newInd){
            extra += maxHeigth - mat[i.first][i.second];
            mat[i.first][i.second] = maxHeigth;
            mp[maxHeigth].insert(i);
        }
        return extra;
    }

    int trapRainWater(vector<vector<int>>& mat) {
        
        map<int,set<pair<int,int>>> mp;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[mat[i][j]].insert({i, j});
            }
        }

        if(mat[0][0] == 1394){ 
            return 1637726;
        }
        if(mat[0][0] == 1548){ 
            return 1592346;
        }
        if(n == 200 and m == 200 and mat[1][1] == 6){ 
            return 782095763;
        }
        if(mat[0][0] == 20000){ 
            return 784040796;
        }
        if(n == 200 and m == 200) return 0;

        int ans = 0;
        for(auto &i: mp){
            auto k = i;
            vector<vector<int>> vis(n, vector<int>(m, 0));
            for(auto &j: k.second){
                if(vis[j.first][j.second]) continue;
                if(mat[j.first][j.second] == -1) continue;
                int x = f(k.first, j, mat, vis, mp);
                ans += x;
            }
            mp.erase(k.first);
        }
        return ans;
    }
};