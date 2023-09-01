class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1, 0);
        for(int i=0; i<=n; i++){
            
            int k = i;
            int cnt = 0;
            while(k > 0){
                cnt += k%2;
                k /= 2;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};