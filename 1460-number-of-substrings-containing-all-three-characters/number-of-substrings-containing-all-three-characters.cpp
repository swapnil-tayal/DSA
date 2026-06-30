class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();
        int ans = 0;

        int i = 0;
        int j = 0;
        int a = 0;
        int b = 0;
        int c = 0;

        while(j < n){

            if(s[j] == 'a') a++;
            else if(s[j] == 'b') b++;
            else c++;

            if(a == 0 || b == 0 || c == 0) j++;
            else{

                while(i < n and a > 0 and b > 0 and c > 0){
                    ans += n-j;
                    if(s[i] == 'a') a--;
                    else if(s[i] == 'b') b--;
                    else c--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};