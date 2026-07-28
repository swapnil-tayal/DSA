class Solution {
public:
    string smallestPalindrome(string s) {
        
        int n = s.size();
        int mid = n/2;
        sort(s.begin(), s.begin()+mid);
        if(n%2) mid++;
        sort(s.begin()+mid, s.end());
        reverse(s.begin()+mid, s.end());
        return s;

    }
};