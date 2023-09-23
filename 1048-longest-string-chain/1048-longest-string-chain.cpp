class Solution{
    
    map<string,int> mp;
public:
    
    int f(int i, vector<string> &words, vector<int> &dp){
        
        if(dp[i] != -1) return dp[i];
        
        int ans = 0;
        for(int j=0; j<words[i].size(); j++){
            string str;
            for(int k=0; k<words[i].size(); k++){
                if(j != k) str += words[i][k];
            }
            if(mp.find(str) != mp.end()){
                ans = max(ans, f(mp[str], words, dp));
            }
        }
        return dp[i] = 1 + ans;
    }
    
    int longestStrChain(vector<string>& words) {
        
        int ans = 1;
        int n = words.size();
        
        for(int i=0; i<n; i++){
            mp[words[i]] = i;
        }
        vector<int> dp(n, -1);
        
        for(int i=0; i<n; i++){
            ans = max(ans, f(i, words, dp));
        }
        return ans;
    }
};