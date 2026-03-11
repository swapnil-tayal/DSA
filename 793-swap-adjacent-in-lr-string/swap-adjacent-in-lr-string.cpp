class Solution {
public:
    bool canTransform(string start, string result) {
        
        int n = start.size();
        int cntl = 0;
        int cntr = 0;

        for(int i=0; i<n; i++){
            
            if(start[i] == 'R') cntr++;
            if(result[i] == 'R'){
                if(cntl || cntr == 0) return 0;
                cntr--;                
            }
            if(result[i] == 'L') cntl++;
            if(start[i] == 'L'){
                if(cntr || cntl == 0) return 0;
                cntl--;
            }
        }
        return cntr == 0 && cntl == 0;
    }
};