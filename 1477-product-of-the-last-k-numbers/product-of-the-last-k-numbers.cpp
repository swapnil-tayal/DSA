class ProductOfNumbers {

    vector<long long> a;
    long long pro = 1;
    long long mod = (1e9+7);
    int n = 0;
    vector<int> zeros;
    int cnt = 0;

    long long power(long long a, long long b) {
        long long res = 1;
        while(b > 0) {
            if(b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long a) {
        return power(a, mod - 2);
    }

public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        n++;
        if(num == 0) cnt++;
        else pro = (pro * num) % mod;
        a.push_back(pro);
        zeros.push_back(cnt);
    }
    
    int getProduct(int k) {
        
        if(k == n){

            if(zeros[n-1]) return 0;
            else return pro;
        }
        if(zeros[n-1] - zeros[n-1-k] > 0) return 0;
        else return pro * modInverse(a[n-1-k]) % mod;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */