class Solution {
public:
    int findComplement(int num) {
        
        int f = 0;
        int ans = 0;
         
        for(int i=31; i>=0; i--){
            
            int bit = (num >> i) & 1;
            
            if(bit == 1){
                f = 1;
            }
            if(f == 1){
                int complementBit = 1 - bit;
                ans = ans | (complementBit << i);
            }
        }
        return ans;
    }
};