class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0;
        int cnt = 0;
        int n = events.size();
        int maxDays = 0;
        for(auto i: events) maxDays = max(maxDays, i[1]);

        for(int day=1; day<=maxDays; day++){

            while(i < n and events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() and pq.top() < day) pq.pop();
            if(!pq.empty()){
                pq.pop();
                cnt++;
            }
        }
        return cnt;
    }
};