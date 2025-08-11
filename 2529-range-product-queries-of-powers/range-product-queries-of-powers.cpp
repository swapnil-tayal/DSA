class Solution {
    int mod = (1e9)+7;
    vector<int> powers;
public:

    int f(int s, int e){
        long long val = 1;
        for(int i=s; i<=e; i++){
            val = (val * powers[i]) % mod; 
        }
        return val;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        bitset<32> bits(n);
        int a = 1;
        for(int i=0; i<32; i++){
            if(bits[i]){
                powers.push_back(a);
            }
            a = (a*2) % mod;
        }
        vector<int> ans;
        for(auto i: queries){
            ans.push_back(f(i[0], i[1]));
        }
        return ans;
    }
};