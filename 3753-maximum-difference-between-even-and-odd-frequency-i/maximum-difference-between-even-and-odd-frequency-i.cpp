class Solution {
public:
    int maxDifference(string s) {
        int odd=-1;
        int even=INT_MAX;
        vector<int> frq(26);
        for(char c:s) frq[c-'a']++;
        for(int i=0;i<26;i++){
            if(frq[i]%2) odd=max(odd,frq[i]);
            else if(frq[i]) even=min(even,frq[i]);
        }
        return odd-even;
    }
};