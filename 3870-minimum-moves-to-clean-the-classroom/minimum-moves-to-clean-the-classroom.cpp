class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        map<pair<int,int>, int> mp;
        int cnt = 0;
        int sx = 0, sy = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(classroom[i][j] == 'L') mp[{i,j}] = cnt++;
                if(classroom[i][j] == 'S') sx = i, sy = j;
            }
        }

        int totalMask = 1 << cnt;

        vector<vector<vector<int>>> best(n, vector<vector<int>>(m, vector<int>(totalMask, -1)));

        queue<vector<int>> q;
        q.push({sx, sy, 0, energy, 0});
        best[sx][sy][0] = energy;

        int row[] = {-1,1,0,0};
        int col[] = {0,0,-1,1};

        int targetMask = totalMask - 1;

        while(!q.empty()){

            int x = q.front()[0];
            int y = q.front()[1];
            int mask = q.front()[2];
            int e = q.front()[3];
            int steps = q.front()[4];
            q.pop();

            if(mask == targetMask) return steps;

            if(e == 0) continue;

            for(int k = 0; k < 4; k++){

                int nx = x + row[k];
                int ny = y + col[k];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(classroom[nx][ny] == 'X') continue;

                int newMask = mask;
                int newEnergy = e - 1;

                if(classroom[nx][ny] == 'L') newMask |= (1 << mp[{nx,ny}]);
                if(classroom[nx][ny] == 'R') newEnergy = energy;
                if(newEnergy <= best[nx][ny][newMask]) continue;
                best[nx][ny][newMask] = newEnergy;
                q.push({nx, ny, newMask, newEnergy, steps+1});
            }
        }

        return -1;
    }
};