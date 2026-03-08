class Solution {
    vector<int> one, zero;
public:

    long long f(string s, int i, int j, int encCost, int flat){

        int n = s.size();
        int ones = one[j] - (i-1 >= 0 ? one[i-1] : 0);
        long long cost = 1e16;
        if(ones > 0){
            cost = 1ll * (j-i+1) * ones * encCost;
        } else cost = flat;

        // cout<<s<<' '<<cost<<'\n';

        if(n % 2 == 0){
            cost = min(cost, f(s.substr(0, n/2), i, j-(n/2), encCost, flat) + f(s.substr(n/2), i+(n/2), j, encCost, flat));
        }
        return cost;
    }

    long long minCost(string s, int encCost, int flatCost) {
        
        int n = s.size();
        int cnt1 = 0;
        int cnt0 = 0;
        cout<<s.size()<<'\n';
        for(int i=0; i<n; i++) {
            if(s[i] == '1') cnt1++;
            else cnt0++;
            one.push_back(cnt1);
            zero.push_back(cnt0);
        }
        return f(s, 0, n-1, encCost, flatCost);
    }
};