class Solution {
public:
    
    long long f(string s, char ch){
        
        long long cnt = 0;
        int n = s.size();
        int f = 0;
        if(n%2 == 1 and s[n/2] != ch){
            cnt += n/2 + 1;
            f = 1;
        }
        int p = n/2 - 1;
        int q = n/2;
        if(n%2) q++;
        
        // cout<<p<<' '<<q<<'\n';
        
        while(p >= 0){
            
            if(f) s[p] == '1' ? s[p] = '0' : s[p] = '1';
            if(s[p] != ch){
                cnt += p+1;
                f = 1-f;
            }p--;
        }
        f = 0;
        while(q < n){
            
            if(f) s[q] == '1' ? s[q] = '0' : s[q] = '1';
            if(s[q] != ch){
                cnt += (n-q);
                f = 1-f;
            }q++;
        }
        // cout<<cnt<<'\n';
        return cnt;
    }
    
    long long minimumCost(string s) {
        
        // f(s, '0');
        // return 0;
        return min(f(s, '0'), f(s, '1'));
    }
};