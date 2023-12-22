class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        string ans;
        
        int ind = 0;
        unordered_map<char,int> mp;
        while(ind < 100000){
            int f = 0;
            for(int i=0; i<n; i++){
                if(strs[i].size() > ind){
                    mp[strs[i][ind]]++;  
                }else f= 1;
            }
            if(mp.size() == 1 and mp.begin()->second == n){
                ans += mp.begin()->first;
            }else break;
            mp.clear();
            ind++;
            if(f) break;
        }
        return ans;
    }
};