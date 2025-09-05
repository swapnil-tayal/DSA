class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        for(int i=1; i<=60; i++){
            long long x = num1;
            x -= (1LL*i*num2);
            if(x < i) return -1;
            if(x == 0) return i;
            int bits = __builtin_popcountll(x);
            if(bits <= i) return i;
        }
        return -1;
    }
};