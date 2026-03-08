class Solution {
public:
    int minOperations(string s) {
        
        int n = s.size();
        
        if(n == 2 and s[0] > s[n-1]) return -1;

        if(is_sorted(s.begin(), s.end())) return 0;
        
        string first = s.substr(0, n-1);
        sort(first.begin(), first.end());
        if(first.back() <= s[n-1]) return 1;

        string last = s.substr(1);
        sort(last.begin(), last.end());
        if(last[0] >= s[0]) return 1;

        string newS = s;
        sort(newS.begin(), newS.begin() + n-1);
        sort(newS.begin()+1, newS.end());
        if(is_sorted(newS.begin(), newS.end())){
            return 2;
        }

        newS = s;
        sort(newS.begin()+1, newS.end());
        sort(newS.begin(), newS.begin() + n-1);
        if(is_sorted(newS.begin(), newS.end())){
            return 2;
        }
        return 3;
    }
};