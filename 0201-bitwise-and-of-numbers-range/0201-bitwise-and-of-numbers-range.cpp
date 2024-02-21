class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        bitset<32> it1(left);
        bitset<32> it2(right);
        
        int lastSet1, lastSet2;
        for(int i=0; i<32; i++){
            if(it1[i] == 1) lastSet1 = i;
            if(it2[i] == 1) lastSet2 = i;
        }
        if(lastSet1 != lastSet2) return 0;
        else{
            int ans = 0;
            for(int i=lastSet2; i>=0; i--){
                if(it1[i] == 1 and it2[i] == 1){
                    ans += (1<<i);
                }else if(it1[i] != it2[i]) break;
            }
            return ans;
            return 0;
        }
    }
};