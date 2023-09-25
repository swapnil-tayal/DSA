class Solution {
public:
    char findTheDifference(string s, string t) {
        
        char ch = 0;
        for(auto i: s) ch ^= i;
        for(auto i: t) ch ^= i;
        return ch;
    }
};