class Solution{
    int ans;
public:
    
    void f(int k, string &s, int &maxLetters){
        
        int n = s.size();
        int i = 0;
        int j = 0;
        map<char, int> mpS;
        map<string, int> mp;
        string str;
        
        while(j < n){
            
            mpS[s[j]]++;
            str += s[j];
            if(j-i+1 < k) j++;
            else{
                
                if(mpS.size() <= maxLetters){
        
                    mp[str]++;
                    ans = max(ans, mp[str]);
                    
                }
                mpS[s[i]]--;
                str = str.substr(1);
                if(mpS[s[i]] == 0) mpS.erase(s[i]);
                i++;
                j++;
            }
        }
    }
    
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        ans = 0;
        for(int i=minSize; i<=maxSize; i++){
            f(i, s, maxLetters);
        }
        return ans;
    }
};