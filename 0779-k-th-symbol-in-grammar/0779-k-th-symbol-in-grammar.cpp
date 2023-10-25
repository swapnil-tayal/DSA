class Solution {
public:
    
    int findN(int x){
        int i = 1;
        while(i < x){
            i = i*2;
        }
        return i/2;
    }
    
    int f(int k){
        
        if(k == 1) return 0;
        if(k == 2) return 1;
        int pow = findN(k);
        int x = k - pow;
        // x = pow - x + 1;
        // cout<<k<<' '<<pow<<' '<<x<<'\n';
        return 1 - f(x);
        
    }
    
    int
        kthGrammar(int n, int k) {
        
        // 0
        // 0 1
        // 01 10
        // 0110 1001
        // 01101001 10010110
        // 01101001 10010110 1001011001101001
        
        return f(k);
    }
};