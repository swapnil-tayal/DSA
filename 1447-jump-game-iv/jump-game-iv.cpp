class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        map<int,set<int>> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]].insert(i);
        }

        queue<int> q;
        q.push(0);
        vector<int> vis(n, 0);
        int cnt = 0;
    
        while(!q.empty()){

            int k = q.size();
            while(k--){
            
                int x = q.front();
                if(x == n-1) return cnt;
                vis[x] = 1;
                q.pop();

                if(x-1 >= 0 and vis[x-1] == 0){
                    q.push(x-1);
                }
                if(x+1 < n and vis[x+1] == 0){
                    q.push(x+1);
                }
                vector<int> temp;
                for(auto &i: mp[arr[x]]){
                    if(vis[i] == 0){
                        q.push(i);
                        temp.push_back(i);
                    }
                }
                for(auto &k: temp) mp[arr[x]].erase(k);
            }
            cnt++;
        }
        return n-1;
    }
};