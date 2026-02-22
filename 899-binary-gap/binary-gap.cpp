class Solution {
public:
    int binaryGap(int n) {
        
        bitset<32> it(n);
        int ans = 0;
        int prev = -1;
        for(int i=0; i<32; i++){
            if(it[i] == 1){
                if(prev == -1) prev = i;
                else{
                    ans = max(ans, i-prev);
                    prev = i;
                }
            }
        }
        return ans;
    }
};