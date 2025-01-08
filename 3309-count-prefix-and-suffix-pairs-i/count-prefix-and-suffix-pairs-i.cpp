class Solution {
public:
    
    int f(string str1, string str2){
        
        if(str2.size() < str1.size()) return 0;
        if(str1 == str2) return 1;
        
        int m = str1.size();
        for(int i=0; i<str1.size(); i++){
            if(str1[i] != str2[i]) return 0;
        }
        
        int ind = 0;
        for(int i=str2.size() - str1.size(); i<str2.size(); i++){
            if(str1[ind++] != str2[i]) return 0;
        }
        return 1;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int cnt = 0;
        int n = words.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                if(f(words[i], words[j])) cnt++;
            }
        }
        return cnt;
    }
};