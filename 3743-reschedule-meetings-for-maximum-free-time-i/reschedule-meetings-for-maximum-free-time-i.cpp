class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        vector<int> gaps;
        int prev = 0;
        for(int i=0; i<startTime.size(); i++){
            gaps.push_back(startTime[i] - prev);
            prev = endTime[i];
        }
        gaps.push_back(eventTime - prev);
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = 0;
        while(j < gaps.size()){

            sum += gaps[j];
            if(j-i+1 < k+1) j++;
            else{
                ans = max(ans, sum);
                sum -= gaps[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};