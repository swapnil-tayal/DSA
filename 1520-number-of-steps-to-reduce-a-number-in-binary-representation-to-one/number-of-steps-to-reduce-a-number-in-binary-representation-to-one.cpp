class Solution {
public:
    
    int f(string &s){
        
        int cnt = 0;
        for(auto i: s) cnt += (i=='1');
        return cnt == 1 and s[s.size()-1] == '1';
    }
    
    void addOne(string &s){
        
        int ind = s.size()-1;
        while(ind >= 0 and s[ind] == '1'){
            s[ind] = '0';
            ind--;
        }
        if(ind == -1) s = '1' + s;
        else s[ind] = '1';
    }
    void half(string &s){
        s.pop_back();
        s = '0' + s;
    }
    
    int numSteps(string s) {
        
        int num = 0;
        int cnt = 0;
        while(!f(s)){
            
            if(s[s.size()-1] != '0') addOne(s);
            else half(s);
            cnt++;
        }
        return cnt;
    }
};