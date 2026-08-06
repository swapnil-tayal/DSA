class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        if(finalSum % 2 == 1) return {};

        vector<long long> ans;
        long long val = 2;
    
        while(val <= finalSum){
            ans.push_back(val);
            finalSum -= val;
            val += 2;
        }
        if(finalSum > 0) ans.back() += finalSum;
        return ans;
    }
};

// 28
// 2 26
// 2 4 22
// 2 4 6 16
// 2 4 6 16