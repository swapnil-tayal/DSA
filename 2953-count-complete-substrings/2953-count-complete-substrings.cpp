class Solution {
public:
    
    int f(string &str, int size, int k){
        
        int i = 0;
        int j = 1;
        unordered_map<char,int> mp;
        mp[str[0]]++;
        int n = str.size();
        int cnt = 0;
            
        while(j < n){
            
            if(abs(str[j]-str[j-1]) > 2){
                while(i < j){
                    mp[str[i]]--;
                    i++;
                }
            }
            mp[str[j]]++;
            if(j-i+1 < size) j++;
            else{
                
                int t = 0;
                for(auto h: mp){
                    if(h.second != k and h.second != 0) t = 1;
                }
                if(!t){
                    cnt++;
                }
                mp[str[i]]--;
                i++;
                j++;
            }
        }
        return cnt;
    }
    
    int countCompleteSubstrings(string str, int k) {
        
        int ans = 0;
        int i = 1;
        if(k == 1) i = 2;
        for(i; i<=26; i++){
            ans += f(str, k*i, k);
        }
        if(k == 1) ans += str.size();
        return ans;
    }
};