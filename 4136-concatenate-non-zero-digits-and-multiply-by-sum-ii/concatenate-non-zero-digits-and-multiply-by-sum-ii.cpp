class Solution {
    
public:

    long long mod = (1e9+7);
    int pow[100001];

    Solution(){
        pow[0] = 1;
        for (int i = 1; i < 100001; i++){
            pow[i] = pow[i - 1] * 10LL % mod;
        }
    };

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        

        int n = s.size();
        vector<long long> num(n+1, 0);
        vector<long long> sum(n+1, 0);
        vector<long long> len(n+1, 0);

        long long sm = 0;
        long long nm = 0;
        for(int i=0; i<n; i++){

            long long val = s[i] - '0';
            sum[i+1] = sum[i] + val;

            if(val != 0){
                num[i+1] = ((num[i] * 10ll) + val) % mod;
                len[i+1] = len[i]+1;
            }
            else{
                num[i+1] = num[i];
                len[i+1] = len[i];
            }
        }

        vector<int> ans;

        for(auto &i: queries){
            
            int l = i[0];
            int r = i[1] + 1;

            long long s1 = num[l] * pow[len[r] - len[l]] % mod;
            long long s2 = (num[r] - s1 + mod) % mod;
            ans.push_back(s2 * (sum[r] - sum[l]) % mod);
        }
        return ans;
    }
};