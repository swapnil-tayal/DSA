class Solution {
public:
    int pivotInteger(int n) {
        
        int x = (n*n) + n;
        if(x%2 == 1) return -1;
        x /= 2;
        
        cout<<sqrt(x)<<'\n';
        
        if((floor)(sqrt(x))*sqrt(x) != x) return -1;
        return sqrt(x);
    }
};