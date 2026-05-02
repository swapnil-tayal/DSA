class Solution {
public:
    
    char rotated(char ch){
        
        if(ch == '0') return '0';
        else if(ch == '1') return '1';
        else if(ch == '8') return '8';
        else if(ch == '2') return '5';
        else if(ch == '5') return '2';
        else if(ch == '6') return '9';
        else if(ch == '9') return '6';
        else return '7';
    }
    
    bool check(string s, int x){
        
        int n = s.size();
        for(int i=0; i<s.size(); i++){
            
            char ch = rotated(s[i]);
            if(ch == '7') return false; 
            s[i] = ch;
        }
        return stoi(s) != x;
    }
     
    int rotatedDigits(int n) {
        
        int cnt = 0;
        for(int i=1; i<=n; i++){
            
            string s = to_string(i);
            if(check(s, i)) cnt++;
        }
        return cnt;
    }
};