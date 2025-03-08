class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int n = blocks.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int white = 0;
        int ans = 1e9;

        while(j < n){

            cnt += (blocks[j] == 'W');
            if(j-i+1 < k) j++;
            else{
                ans = min(ans, cnt);
                cnt -= (blocks[i] == 'W');
                i++;
                j++;
            }
        }   
        return ans;
    }
};