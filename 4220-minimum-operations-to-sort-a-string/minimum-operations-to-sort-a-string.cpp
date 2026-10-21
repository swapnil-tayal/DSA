class Solution {
public:
    int minOperations(string s) {
        
        int n = s.size();

        if(is_sorted(s.begin(), s.end())) return 0;
        if(n <= 2) return -1;

        char mini = *min_element(s.begin(), s.end());
        char maxi = *max_element(s.begin(), s.end());

        unordered_map<char,int> mp;
        for(auto &i: s) mp[i]++;

        if(s[0] == mini) return 1;
        if(s[n-1] == maxi) return 1;
        if(s[n-1] == mini and s[0] == maxi and mp[mini] == 1 and mp[maxi] == 1) return 3;
        return 2;
    }
};