class Solution {
    
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
        return 1 - f(x);
        
    }
    
    public int kthGrammar(int n, int k) {
        
        return f(k);
        
            
    }
}