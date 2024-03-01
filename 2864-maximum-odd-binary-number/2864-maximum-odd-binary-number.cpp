class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int cnt = 0;
        int n = s.size();
        for(auto i: s){
            if(i == '1') cnt++;
        }
        string ans;
        if(cnt == 1){
            
            for(int i=0; i<n-1; i++){
                ans += '0';
            }
            ans += '1';
        
        }else{
            
            int i = 0;
            while(cnt > 1 and i < n-1){
                ans += '1';
                cnt--;
                i++;
            }
            while(i < n-1){
                ans += '0';
                i++;
            }ans += '1';
        }
        return ans;
    }
};