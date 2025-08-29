class Solution {
public:
    long long flowerGame(int n, int m) {
        
        long long evenN = n/2;
        long long oddN = n - evenN;
        long long evenM = m/2;
        long long oddM = m - evenM;
        return (evenN * oddM) + (evenM * oddN);
    }
};