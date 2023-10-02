class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int cntA = 0;
        int cntB = 0;
        int i = 0;
        int n = colors.size();
        
        while(i < n){
            
            int temp = 0;
            if(colors[i] == 'A'){
                while(i < n and colors[i] == 'A'){
                    temp++;
                    i++;
                }
                cntA += max(0, temp-2);
            }else if(colors[i] == 'B'){
                while(i < n and colors[i] == 'B'){
                    temp++;
                    i++;
                }
                cntB += max(0, temp-2);
            }
        }
        return cntA > cntB && cntA >= 1;
    }
};