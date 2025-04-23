class Solution {
public:
    int countLargestGroup(int n) {
        
        map<int,int> mp1;
        map<int,int> mp2;
        int maxi = 0;
        int cnt = 0;
        for(int i=1; i<=n; i++){
            int sm = 0;
            int x = i;
            while(x > 0){
                sm += x%10;
                x = x/10;
            }
            mp1[sm]++;
            int val = mp1[sm];
            if(val > maxi){
                maxi = val;
                cnt = 1;
            }else if(val == maxi){
                cnt++;
            }
        }
        return cnt;
    }
};