class Solution {
public:
    long long minEnd(int n, int x) {
        
        bitset<64> it(x);
        bitset<64> it2(n-1);
        int ind = 0;
        
        for(int i=0; i<=63; i++){
            if(it[i] == 0){
                it[i] = it2[ind++];
            }
        }
        long long ans = 0;
        for(int i=0; i<=63; i++){
            if(it[i]) ans += pow(2, i);
        }
        return ans;
    }
};