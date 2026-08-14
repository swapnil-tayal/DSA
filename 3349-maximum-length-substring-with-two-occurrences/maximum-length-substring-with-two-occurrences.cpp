class Solution {
public:
    int maximumLengthSubstring(string s) {
      
        int n = s.size();
        int maxi = 0;
        
        for(int i=0; i<n; i++){
            unordered_map<char,int> mp;
            int cnt = 0;
            for(int j=i; j<n; j++){
                mp[s[j]]++;
                cnt++;
                int f = 0;
                for(auto &k: mp){
                    if(k.second > 2) f = 1;
                }    
                if(!f) maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};