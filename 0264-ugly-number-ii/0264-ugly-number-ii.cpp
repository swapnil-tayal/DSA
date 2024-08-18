class Solution {
public:
    int nthUglyNumber(int n) {
        
        set<int> st;
        st.insert(1);
        int cnt = 1;
        
        while(cnt < n){
            
            long long newNum = 1e12;
            set<int> eliminate;
            for(auto &i: st){
                int isAny = 0;
                if(st.count(i*2ll) == 0){
                    newNum = min(newNum, i*2ll);
                    isAny++;
                }
                if(st.count(i*3ll) == 0){
                    newNum = min(newNum, i*3ll);
                    isAny++;
                }
                if(st.count(i*5ll) == 0){
                    newNum = min(newNum, i*5ll);
                    isAny++;
                }
                if(isAny == 0) eliminate.insert(i);
            }
            if(newNum != 1e12){
                st.insert(newNum);
                cnt++;
            }
            for(auto i: eliminate) st.erase(i);
        }
        return *st.rbegin();
        
    }
};