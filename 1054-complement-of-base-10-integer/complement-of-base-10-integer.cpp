class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 1) return 0;
        if(n == 0) return 1;
        
        bitset<32> it(n);
        long long num = 0;
        long long x = 1;
        int ind = 0;
        for(int i=0; i<32; i++){
            if(it[i] == 1) ind = i;
        }
        for(int i=0; i<ind; i++){
            if(it[i] == 0) num += x;
            x *= 2;
        }
        return num;
    }
};