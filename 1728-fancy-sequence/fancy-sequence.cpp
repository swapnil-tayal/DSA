class Fancy {
    vector<long long> a;
    long long add = 0;
    long long mul = 1;
    long long mod = 1e9+7;
    long long modPow(long long x, long long y, long long mod) {
        long long res = 1;
        x = x % mod;
        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * x) % mod;
            }
            y = y / 2;
            x = (x * x) % mod;
        }
        return res;
    }
public:
    Fancy() {
        
    }
    
    void append(int val) {
        val = (val - add + mod) % mod;
        val = val * modPow(mul, mod-2, mod) % mod;
        a.push_back(val);
    }
    
    void addAll(int inc) {
        add = (add + inc) % mod;
    }
    
    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }
    
    int getIndex(int idx) {
        if(idx+1 > a.size()) return -1;
        return (a[idx] * mul + add) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */