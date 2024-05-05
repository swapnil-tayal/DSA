class Solution {
public:
    
    int f(string &s, int k){
        
        int n = s.size();
        map<char,int> mp;
        
        int i = 0;
        while(i<k) mp[s[i++]]++;
        
        while(i < n){
            
            int next = i+k;
            map<char,int> mp2;
            
            while(i < next) mp2[s[i++]]++;

            for(auto &h: mp){
                if(mp2[h.first] != h.second) return 0;
            }
        }
        return 1;
    }
    
    int minAnagramLength(string s) {
        
        int n = s.size();
        int cnt = 0;
        
        for(int k=1; k<=n; k++){
            
            if(n%k == 0){
                if(f(s, k)) return k;
            }
        }
        return n;
    }
};