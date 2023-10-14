class Solution {
    vector<string> ansF;
    int size;
public:
    
    bool isValid(string &s1, string &s2){
        
        if(s1.size() != s2.size()) return 0;
        int cnt = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]) cnt++;
            if(cnt > 1) return 0;
        }
        return cnt == 1;
    }
    
    
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(int i=0; i<n; i++) hash[i] = i;
        int maxi = -1;
        int ind = -1;
        
        for(int i=0; i<n; i++){
            for(int prev=0; prev < i; prev++){
                if(groups[prev] != groups[i] and isValid(words[prev], words[i])){
                
                    if(dp[i] < dp[prev] + 1){
                        dp[i] = dp[prev] + 1;
                        hash[i] = prev;
                    }
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                ind = i;
            }
        }
        // for(auto i: hash) cout<<i<<' ';
        vector<string> ans;
        while(hash[ind] != ind){
            ans.push_back(words[ind]);
            ind = hash[ind];
        }
        ans.push_back(words[ind]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};