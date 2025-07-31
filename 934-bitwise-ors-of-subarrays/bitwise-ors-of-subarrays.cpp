class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        
        set<int> uniqAcrossAll;
        set<int> UnqTillPrev;

        for(auto i: arr){

            set<int> UnqTillNow;
            UnqTillNow.insert(i);
            for(auto k: UnqTillPrev){
                UnqTillNow.insert(k | i);
            }
            uniqAcrossAll.insert(UnqTillNow.begin(), UnqTillNow.end());
            UnqTillPrev = UnqTillNow;
        }
        return uniqAcrossAll.size();
    }
};