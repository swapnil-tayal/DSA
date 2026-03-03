class Solution {
public:
    char findKthBit(int n, int k) {
        
        string s = "0";
        for(int i=0; i<n-1; i++){
            string inv = "";
            for(auto &k: s) inv += (k=='0' ? '1' : '0');
            reverse(inv.begin(), inv.end());
            s = s + "1" + inv;
        }
        return s[k-1];
    }
};