class Solution {
public:
    int passThePillow(int n, int time) {
        
        int curr = 1;
        int dir = 1;
        while(time--){
            
            if(curr == n){
                curr = n-1;
                dir = 0;
            }
            else if(curr == 1){
                curr = 2;
                dir = 1;
            }else{
                if(dir) curr++;
                else curr--;
            }
        }
        return curr;
    }
};