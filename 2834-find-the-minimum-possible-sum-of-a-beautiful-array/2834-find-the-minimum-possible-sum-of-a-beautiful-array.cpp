class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        
        long long sm = 0;
        int i = 1;
        set<int> st;
        int cnt = 0;
        
        while(cnt != n){
            
            if(st.count(i)) i++;
            else{
                
                st.insert(target-i);
                sm += i;
                i++;
                cnt++;
            }
        }
        return sm;
    }
};