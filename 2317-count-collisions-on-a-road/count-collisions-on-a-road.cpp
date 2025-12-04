class Solution {
public:
    int countCollisions(string directions) {
        
        char ch = '-';
        int ans = 0;
        int temp = 0;
        for(auto &i: directions){

            if(ch == '-') ch = i;
            else if(i == 'R'){
                if(ch == 'R') temp++;
                ch = 'R';
            }else if(i == 'L'){
                if(ch == 'R'){ 
                    ans += 2; 
                    ch = 'S';
                    ans += temp;
                    temp = 0; 
                }
                else if(ch == 'S'){ ans++; ch = 'S'; }
                else ch = 'L';
            }else{
                if(ch == 'R'){
                    ans++;
                    ans += temp;
                    temp = 0;
                }
                ch = 'S';
            }
            // cout<<ans<<' '<<ch<<'\n';
        }
        return ans;
    }
};