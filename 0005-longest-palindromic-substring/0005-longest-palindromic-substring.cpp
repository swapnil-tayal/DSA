class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        string str = "#";
        for(int i=0; i<n; i++){
            str += s[i];
            str += '#';
        }
        // for(auto i: str) cout<<i<<' ';
        // cout<<'\n';
        
        vector<int> P(str.size(), 0);
        int center = 0;
        int right = 0;
        for(int i=0; i<str.size(); i++){
             
            // find corresponding palidromic character
            int iMirror = center - (i-center);
            if(right > i){
                P[i] = min(P[iMirror], right-i);
            }
            // expanding around center i
            int k = P[i];
            while(i+1+P[i] < str.size() and i-1-P[i] >= 0 and str[i+1+P[i]] == str[i-1-P[i]]){
                P[i]++;
            }
            // P[i] = k;
            // if palidrome centered at i expandes r, update c,r
            if(i + P[i] > right){
                center = i;
                right = i + P[i];
            }
        }
        int maxPali = 0;
        int maxCenter = 0;
        for(int i=0; i<str.size(); i++){
            if(maxPali < P[i]){
                maxPali = P[i];
                maxCenter = i;
            }    
        }
        return s.substr(( maxCenter-maxPali )/2, maxPali);
    }
};