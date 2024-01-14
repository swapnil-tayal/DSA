class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        vector<int> mp1(26, 0), mp2(26, 0);
        set<int> st1, st2;
        for(auto &i: word1){
            mp1[i-'a']++;
            st1.insert(i);
        }
        for(auto &i: word2){
            mp2[i-'a']++;
            st2.insert(i);
        }
        sort(mp1.begin(), mp1.end());
        sort(mp2.begin(), mp2.end());
        return mp1 == mp2 and st1 == st2;
    }
};