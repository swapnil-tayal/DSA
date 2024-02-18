class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        
        long long cnt = 0;
        map<string, int> mp;
        map<string, int> rmp;
        
        vector<string> rwords = words;
        for(auto &i: rwords) reverse(i.begin(), i.end());
        
        for(int i=0; i<words.size(); i++){
            
            string str = words[i];
            
            int m = str.size();
            string pre = "";
            string suf = "";
            
            for(int k=0; k<m; k++){
                
                pre += str[k];
                suf += str[m-1-k];
                
                // cout<<pre<<' '<<suf<<'\n';
                
                if(mp.find(pre) != mp.end() and rmp.find(suf) != rmp.end()){
                    
                    string rev = suf;
                    reverse(rev.begin(), rev.end());
                    if(rev == pre){
                        cnt += mp[pre];
                    }
                }
            }
            mp[words[i]]++;
            rmp[rwords[i]]++;
        }
        return cnt;
    }
};