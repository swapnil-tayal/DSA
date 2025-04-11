class Solution {
public:

    int f(int x){

        string str = to_string(x);
        int n = str.size();
        if(n%2) return 0;

        int cnt = 0;
        int cnt2 = 0;
        for(int i=0; i<n; i++){
            if(i < n/2) cnt += (str[i]-'0');
            else cnt2 += (str[i]-'0');
        }
        // cout<<cnt<<' '<<cnt2<<' '<<str<<'\n';
        return cnt == cnt2;
    }

    int countSymmetricIntegers(int low, int high) {
        
        // cout<<f(22);
        // return 0;
        int ans = 0;
        for(int i=low; i<=high; i++){
            ans += f(i);
        }
        return ans;
    }
};