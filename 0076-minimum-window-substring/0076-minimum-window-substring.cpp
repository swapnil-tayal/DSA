class Solution {
public:
    
    int f(vector<int> &tMap, vector<int> &sMap){
        
        for(int i=0; i<64; i++){
            if(tMap[i] != 0 and sMap[i] < tMap[i]) return 0;
        }return 1;
    }
    
    string minWindow(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        if(m > n) return "";
        // if(m == n){
        //     if(s == t) return s;
        //     return "";
        // }
        
        vector<int> tMap(64, 0), sMap(64, 0);
        for(auto &i: t){
            if(i >= 'a' and i <= 'z') tMap[i-'a'+26]++;
            else tMap[i-'A']++;
        }
        
        int j = 0;
        int i = 0;
        int ans = 1e9;
        pair<int,int> pr = {-1,-2};
            
        while(j < n){
            
            if(s[j] >= 'a' and s[j] <= 'z') sMap[s[j]-'a'+26]++;
            else sMap[s[j]-'A']++;
            
            if(!f(tMap, sMap)) j++;
            else{
                
                // cout<<i<<' '<<j<<'\n';        
                // for(auto i: tMap) cout<<i<<' ';
                // cout<<'\n';
                // for(auto i: sMap) cout<<i<<' ';
                // cout<<'\n';
                
                if(j-i+1 < ans){
                    ans = j-i+1;
                    pr = {i,j};
                }
                
                while(f(tMap, sMap)){
                                    
                    if(j-i+1 < ans){
                        ans = j-i+1;
                        pr = {i,j};
                    }
                    if(s[i] >= 'a' and s[i] <= 'z') sMap[s[i]-'a'+26]--;
                    else sMap[s[i]-'A']--;
                    i++;
                }       
                
                // cout<<i<<' '<<j<<'\n';  
                // for(auto i: tMap) cout<<i<<' ';
                // cout<<'\n';
                // for(auto i: sMap) cout<<i<<' ';
                // cout<<'\n';
                
                j++;
            }
        }
        string str;
        for(int k=pr.first; k<=pr.second; k++) str += s[k];
        return str;
    }
};