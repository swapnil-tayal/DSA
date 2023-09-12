class Solution {
public:
    
    int f(int i, int j, string &s, string &p){
        
        if(i == -1){
            if(j != -1){
                if(j%2 == 0) return 0;
                else{
                    while(j > 0){
                        if(p[j] != '*') return 0;
                        j-=2;
                    }return 1;
                }
            }
            else return  j == -1;
        }
        if(i == -1 || j == -1) return 0;
        
        if(p[j] != '*' and p[j] != '.'){
            
            if(s[i] != p[j]) return 0;
            else return f(i-1, j-1, s, p);
            
        }else if(p[j] == '.'){
            
            return f(i-1, j-1, s, p);
            
        }else{
            
            int ch = p[j-1];
            if(ch != '.'){
                
                if(s[i] != ch){
                    return f(i, j-2, s, p);
                }
                else{
                    int pickNow = f(i-1, j-2, s, p);
                    int npickNow = f(i-1, j, s, p);
                    int zeropickNow = f(i, j-2, s, p);
                    return pickNow || npickNow || zeropickNow;
                }
                
            }else{
                int pickNow = f(i-1, j-2, s, p);
                int npickNow = f(i-1, j, s, p);
                int zeropickNow = f(i, j-2, s, p);
                return pickNow || npickNow || zeropickNow;
            }
        }
    }
    
    bool isMatch(string s, string p) {
        
        return f(s.size()-1, p.size()-1, s, p);
    }
};