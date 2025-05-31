class Solution {
    map<int,int> mp;
public:

    void makeMap(vector<vector<int>> &board){
        int n = board.size();
        int var = 1;
        int cnt = 1;
        for(int i=n-1; i>=0; i--){
            if(var == 1){
                for(int j=0; j<n; j++) mp[cnt++] = board[i][j];
            }else{
                for(int j=n-1; j>=0; j--) mp[cnt++] = board[i][j];    
            }var = 1 - var;
        }
    }

    int bfs(vector<vector<int>> &board){
        
        int n = board.size();
        vector<int> vis(n*n+1);
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        int steps = 0;

        while(q.size()){

            int k = q.size();
            while(k--){

                int ind = q.front();
                q.pop();
                if(ind == n*n) return steps;

                for(int i=1; i<=6; i++){
                    int next = ind + i;
                    if(next>n*n) continue;
                    int dest = mp[next] != -1 ? mp[next] : next;
                    if(!vis[dest]){
                        vis[dest] = 1;
                        q.push(dest);
                    }
                }
            }
            steps++;
        }
        return -1;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        makeMap(board);
        return bfs(board);
    }
};