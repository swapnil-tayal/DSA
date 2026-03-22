class RLEIterator {
    int ind = 0;
    vector<int> a;
public:
    RLEIterator(vector<int>& encoding) {
        a = encoding;
    }
    
    int next(int n) {
        
        while(ind < a.size() and n > 0){
            if(a[ind] >= n){
                a[ind] -= n;
                return a[ind+1];
            }else{
                n -= a[ind];
                a[ind] = 0;
                ind += 2;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */