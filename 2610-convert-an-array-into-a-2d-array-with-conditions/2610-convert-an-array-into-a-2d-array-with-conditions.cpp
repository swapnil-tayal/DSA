class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        priority_queue<pair<int,int>> pq;
        map<int,int> mp;
        for(auto &i: nums){
            mp[i]++;
        }
        for(auto &i: mp){
            pq.push({ i.second, i.first });
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            
            int cnt = pq.top().first;
            int val = pq.top().second;
            pq.pop();
            if(ans.size() == 0){
                for(int i=0; i<cnt; i++){
                    ans.push_back({ val });
                }
            }else{
                for(int i=0; i<cnt; i++){
                    ans[i].push_back(val);
                }
            }
        }
        return ans;
    }
};