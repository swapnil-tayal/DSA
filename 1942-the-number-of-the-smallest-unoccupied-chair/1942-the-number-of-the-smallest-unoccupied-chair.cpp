class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n = times.size();
        
        map<int,int> mp;
        int seat = 0;
        
        vector<pair<int,vector<int>>> a(1e5+1, {-1, vector<int>()});
        for(int i=0; i<n; i++){
            a[times[i][0]].first = i;
            a[times[i][1]].second.push_back(i);
        }
        
        priority_queue<int, vector<int>, greater<>> pq;
        for(int i=0; i<=1e5; i++) pq.push(i);
        int targetStart = times[targetFriend][0];
        
        for(auto &i: a){
            if(i.second.size() != 0){
                for(auto &k: i.second){
                    int chair = mp[k];
                    pq.push(chair);
                }
            }
            if(i.first != -1){
                
                if(i.first == targetFriend) return pq.top();
                mp[i.first] = pq.top();
                pq.pop();
            }
        }
        return 69;
    }
};