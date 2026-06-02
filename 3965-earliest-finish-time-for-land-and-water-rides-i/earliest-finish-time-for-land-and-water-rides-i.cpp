class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int landFirstEnd = 1e9;
        for (int i = 0; i < landStartTime.size(); i++) {
            landFirstEnd = min(landFirstEnd, landStartTime[i] + landDuration[i]);
        }

        int finish1 = 1e9;
        for (int i = 0; i < waterStartTime.size(); i++) {
            finish1 = min(finish1, max(landFirstEnd, waterStartTime[i]) + waterDuration[i]);
        }

        int waterFirstEnd = 1e9;
        for (int i = 0; i < waterStartTime.size(); i++) {
            waterFirstEnd = min(waterFirstEnd, waterStartTime[i] + waterDuration[i]);
        }

        int finish2 = 1e9;
        for (int i = 0; i < landStartTime.size(); i++) {
            finish2 = min(finish2, max(waterFirstEnd, landStartTime[i]) + landDuration[i]);
        }

        return min(finish1, finish2);
    }
};