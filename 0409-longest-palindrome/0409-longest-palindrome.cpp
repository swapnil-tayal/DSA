class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int>mp;
        for(auto i:s){
            mp[i]++;

        }
        bool flag = true;
        int ans = 0;
        for(auto i: mp){
            if(i.second % 2 == 0){
                ans += i.second;
            }else{
                ans += i.second - 1;
                flag = false;
            }
        }
          if (!flag) {
              ans += 1;
          }   
               return ans;
    }
};