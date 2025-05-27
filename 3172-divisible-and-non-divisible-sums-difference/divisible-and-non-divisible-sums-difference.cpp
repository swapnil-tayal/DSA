class Solution {
public:
    int differenceOfSums(int n, int m) {

        int s1 = 0;
        int s2 = 0;
        for(int i=1; i<=n; i++){
            s1 += (i%m != 0) ? i : 0;
            s2 += (i%m == 0) ? i : 0;
        }
        return s1-s2;
    }
};