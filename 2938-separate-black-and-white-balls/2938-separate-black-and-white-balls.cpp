class Solution {
public:
    long long minimumSteps(string s) {
        
        int n = s.size();
        long long ans = 0;
        int cnt = 0;
        
        for(int i=n-1; i>=0; i--){
            
            if(s[i] == '0') cnt++;
            else ans += cnt;
        }
        return ans;
    }
};