class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        
        int prev = 0;
        if(startTime.size() == 0) return eventTime;

        startTime.insert(startTime.begin(), 0);
        endTime.insert(endTime.begin(), 0);
        startTime.insert(startTime.end(), eventTime);
        endTime.insert(endTime.end(), eventTime);

        priority_queue<int> pq;
        for(int i=0; i<startTime.size(); i++){
            int diff = startTime[i]-prev;
            pq.push(diff);
            prev = endTime[i];
        }

        int ans = 0;
        for(int i=1; i<startTime.size()-1; i++){
            int prevDiff = startTime[i] - endTime[i-1];
            int nextDiff = startTime[i+1] - endTime[i];
            int currSize = endTime[i] - startTime[i];
            // cout<<prevDiff<<' '<<currSize<<' '<<nextDiff<<'\n';
            ans = max(ans, prevDiff + nextDiff);
            
            vector<int> rem;
            int maxi = max(nextDiff, prevDiff);
            int mini = min(nextDiff, prevDiff);
            if(pq.size() && pq.top() == maxi){
                int top = pq.top();
                rem.push_back(top);
                pq.pop();
            }
            if(pq.size() && pq.top() == mini){
                int top = pq.top();
                rem.push_back(top);
                pq.pop();
            }
            if(pq.size() && pq.top() >= currSize){
                ans = max(ans, prevDiff + nextDiff + currSize);
            }
            for(auto i: rem) pq.push(i);
        }
        return ans;
    }
};