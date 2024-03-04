class Solution {
public:

    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        
        int l = 0;
        int r = n-1;
        int ans = 0;
        int score = 0;
        
        while(l <= r){
            
            if(tokens[l] <= power){
                power -= tokens[l];
                score++;
                l++;
                ans = max(ans, score);
                
            }else if(score >= 1){
                power += tokens[r];
                score--;
                r--;
                
            }else break;
        }
        return ans;
    }
};