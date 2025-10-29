class Solution {
public:
    int smallestNumber(int n) {
        return pow(2, log2(1 << (int)log2(n))+1) - 1;
    }
};