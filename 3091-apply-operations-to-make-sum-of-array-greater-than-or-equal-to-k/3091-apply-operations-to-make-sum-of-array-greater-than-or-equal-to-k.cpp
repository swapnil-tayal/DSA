class Solution {
public:
    int minOperations(int k) {
        
        int opr = k;
        if(k == 1) return 0;
        
        for(int i=1; i<=k; i++){
            
            int cntInc = i-1;
            int left = k-i;
            
            int cntDup = (left + i-1)/i;
            opr = min(opr, cntDup+cntInc);
        }
        return opr;
    }
};