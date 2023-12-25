class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        vector<int> inD(numCourses);
        for(auto i: pre) inD[i[1]]++;
        vector<int> adj[numCourses];
        
        for(auto i: pre){
            adj[i[0]].push_back(i[1]);
        }
        
        queue<int> q;
        vector<int> topo;
        
        for(int i=0; i<numCourses; i++){
            if(inD[i] == 0){
                q.push(i);
                topo.push_back(i);
            }
        }
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto i: adj[node]){
                
                inD[i]--;
                if(inD[i] == 0){
                    q.push(i);
                    topo.push_back(i);
                }
            }
        }
        return topo.size() == numCourses;
    }
};