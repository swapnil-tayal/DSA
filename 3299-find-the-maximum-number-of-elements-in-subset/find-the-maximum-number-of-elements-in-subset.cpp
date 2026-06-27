class Solution {
public:

    int maximumLength(vector<int>& nums) {
        
        unordered_map<int, int> mainMp;
        for(auto &i: nums) mainMp[i]++;
        int ans = 0;
        ans = max(ans, mainMp[1]%2 ? mainMp[1] : mainMp[1]-1);
        unordered_map<int, int> mp = mainMp;

        for(int i=1; i<=500; i++){

            int res = 0;
            int last = 0;
            mp = mainMp;

            for(int k=0; k<=4; k++){

                int pw = pow(2, k);
                int val = i;
                long long num = i;
                int f = 1;
                for(int q=1; q<pw; q++){
                    num = num * val;
                    if(num >= 1e9){
                        f = 0;
                        break;
                    }
                }
                if(f == 0) break;
                // cout<<num<<' '<<mp[num]<<' '<<last<<'\n';
                if(last == 0){
                    if(mp[num] >= 2){
                        res += 2;
                        last = 2;
                        mp[num] -= 2;
                    }else if(mp[num] == 1){
                        res++;
                        last = 3;
                        break;
                    }
                }else if(last == 2){
                    if(mp[num] >= 2){
                        res += 2;
                        last = 2;
                        mp[num] -= 2;
                    }else if(mp[num] == 1){
                        last = 3;
                        res++;
                        break;
                    } 
                    else break;
                }
            }
            if(last == 3) ans = max(ans, res);
            if(last == 2) ans = max(ans, res-1);
        }
        return ans;
    }
};