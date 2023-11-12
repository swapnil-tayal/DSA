class Solution {
public:
    int distributeCandies(int n, int limit) {
        
        int cnt = 0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                for(int k=0; k<=n; k++){
                    
                    if(i <= limit and j <= limit and k <= limit and i+j+k == n){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};