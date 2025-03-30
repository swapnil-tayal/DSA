class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.size();
        int str = 0;
        map<char,int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]] = i;
        }

        int end = mp[s[0]];
        vector<int> ans;

        for(int i=0; i<n; i++){

            if(mp[s[i]] > end){
                end = mp[s[i]];

            }else if(i == end) {
                ans.push_back(end-str+1);
                if(i+1 < n){
                    str = i+1;
                    end = mp[s[i+1]];
                }
            }
        }
        return ans;
    }
};