class Solution {
public:
    int minFlips(string s) {

        int n = s.size();
        s += s;
        int i = 0;
        int j = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        int ans = 1e9;
        while(j < s.size()){

            if(j%2 == 0) s[j] == '1' ? cnt1++ : cnt2++;
            else s[j] == '0' ? cnt1++ : cnt2++;
            
            if(j-i+1 < n) j++;
            else{

                ans = min(ans, min(cnt1, cnt2));
                if(i%2 == 0) s[i] == '1' ? cnt1-- : cnt2--;
                else s[i] == '0' ? cnt1-- : cnt2--;
                i++;
                j++;
            }
        }
        return ans;
    }
};