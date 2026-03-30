class Solution {
public:
    bool checkStrings(string s1, string s2) {
        
        string str1, str2;
        for(int i=0; i<s1.size(); i++){
            
            if(i%2 == 0) str1 += s1[i];
            else str2 += s1[i];
        }
        string ktr1, ktr2;
        for(int i=0; i<s2.size(); i++){
            
            if(i%2 == 0) ktr1 += s2[i];
            else ktr2 += s2[i];
        }
        
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        sort(ktr1.begin(), ktr1.end());
        sort(ktr2.begin(), ktr2.end());
        
        return str1 == ktr1 and str2 == ktr2;
    }
};