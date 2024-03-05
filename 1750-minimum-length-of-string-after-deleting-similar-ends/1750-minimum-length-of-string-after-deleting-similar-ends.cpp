class Solution {
public:
    int minimumLength(string s) {
        
        int n = s.size();
        int i = 0;
        int j = n-1;
        int ans = n;
        
        while(i < j){
            
            char ch1 = s[i];
            char ch2 = s[j];
            if(ch1 == ch2){
                
                while(i<=j and s[i] == ch1) i++;
                while(i<=j and s[j] == ch2) j--;
                ans = (j-i+1);
            }else break;
        }
        return ans;
    }
};