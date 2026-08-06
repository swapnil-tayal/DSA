class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        if(finalSum % 2 == 1) return {};
    
        unordered_set<long long> st;
        long long val = 2;
    
        while(val < finalSum){
            if(2*val != finalSum && !st.count(val) and !st.count(finalSum - val)){
                st.insert(val);
                finalSum -= val;
            }
            val += 2;
            // cout<<val<<' '<<finalSum<<'\n';
        }
        if(finalSum > 0) st.insert(finalSum);
        vector<long long> a(st.begin(), st.end());
        return a;
    }
};

// 28
// 2 26
// 2 4 22
// 2 4 6 16
// 2 4 6 16