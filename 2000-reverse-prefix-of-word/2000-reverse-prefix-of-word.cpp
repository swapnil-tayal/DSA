class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int n = word.size();
        int ind = word.find(ch);
        if(ind == n) return word;
        reverse(word.begin(), word.begin()+ind+1);
        return word;
    }
};