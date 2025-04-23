class Solution {
public:
    int countLargestGroup(int n) {
        
        map<int,int> mp1;
        map<int,int> mp2;
        for(int i=1; i<=n; i++){
            int sm = 0;
            int x = i;
            while(x > 0){
                sm += x%10;
                x = x/10;
            }
            // cout<<i<<' '<<sm<<'\n';
            mp1[sm]++;
        }
        int maxi = 0;
        for(auto &i: mp1) maxi = max(maxi, i.second);
        int cnt = 0;
        for(auto i: mp1){
            if(i.second == maxi) cnt++;  
        }
        return cnt;
    }
};