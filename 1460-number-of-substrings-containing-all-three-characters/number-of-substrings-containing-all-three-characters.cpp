class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        map<int,int> mp;

        while(j < n){

            if(s[j] == 'a' || s[j] == 'b' || s[j] == 'c') mp[s[j]]++;
            if(mp.size() < 3) j++;
            else{

                while(mp.size() == 3){
                    ans += n-j;
                    if(s[i] == 'a' || s[i] == 'b' || s[i] == 'c') mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }   
        return ans;
    }
};