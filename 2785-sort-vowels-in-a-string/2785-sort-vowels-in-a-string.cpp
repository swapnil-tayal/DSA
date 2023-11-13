class Solution {
public:
    
    int f(char ch){
        
        if(ch == 'A' || ch == 'a' ||
           ch == 'E' || ch == 'e' ||
           ch == 'I' || ch == 'i' ||
           ch == 'O' || ch == 'o' ||
           ch == 'U' || ch == 'u') return 1;
        return 0;
    }
    
    string sortVowels(string s) {
        
        int n = s.size();
        vector<char> chr;
        
        for(auto i: s){
            if(f(i)) chr.push_back(i);
        }
        sort(chr.begin(), chr.end());
        int j = 0;
        for(auto &i: s){
            if(f(i)) i = chr[j++];
        }
        return s;
    }
};