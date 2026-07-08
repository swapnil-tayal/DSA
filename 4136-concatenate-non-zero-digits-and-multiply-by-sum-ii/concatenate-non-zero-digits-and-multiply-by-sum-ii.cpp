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
        vector<long long> num(n, 0);
        vector<long long> sum(n, 0);
        vector<long long> len(n, 0);

        long long sm = 0;
        long long nm = 0;
        for(int i=0; i<n; i++){

            long long val = s[i] - '0';
            sum[i] = (i-1 >= 0 ? sum[i-1] : 0) + val;

            if(val != 0){
                num[i] = ((i-1 >= 0 ? (num[i-1] * 10ll) : 0) + val) % mod;
                len[i] = (i-1 >= 0 ? len[i-1] : 0) + 1;
            }
            else{
                num[i] = i-1 >= 0 ? num[i-1] : 0;
                len[i] = i-1 >= 0 ? len[i-1] : 0;
            }
        }

        vector<int> ans;
        // for(auto i: num) cout<<i<<' ';
        // cout<<'\n';

        for(auto &i: queries){
            
            int l = i[0]-1;
            int r = i[1];

            long long s1 = (l >= 0 ? num[l] : 0) * pow[len[r] - (l >= 0 ? len[l]: 0)] % mod;
            long long s2 = (num[r] - s1 + mod) % mod;
            ans.push_back(s2 * (sum[r] - (l >= 0 ? sum[l] : 0)) % mod);
        }
        return ans;
    }
}; 