class Solution {
public:
    int numberOfChild(int n, int k) {
        
        int ch = 0;
        int direction = 0;
        if(k == 0) return 0;
        
        while(k > 0){
            
            if(ch == n-1){
                ch = n-2;
                direction = 1;
            }else if(ch == 0){
                ch = 1;
                direction = 0;
            }
            else if(direction == 0) ch++;
            else ch--;
            k--;
            if(k == 0) return ch;
        }
        return 0;
    }
};