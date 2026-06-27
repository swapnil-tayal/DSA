class Solution {
public:

    int maximumLength(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        for(auto &i: nums) mp[i]++;
        int ans = 0;
        ans = max(ans, mp[1]%2 ? mp[1] : mp[1]-1);
        unordered_set<int> st;
        for(auto i: nums) st.insert(i);

        for(auto &i: st){

            if(i == 1) continue;
            int res = 0;
            int last = 0;

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
                if(last == 0){
                    if(mp[num] >= 2){
                        res += 2;
                        last = 2;
                    }else if(mp[num] == 1){
                        res++;
                        last = 3;
                        break;
                    }
                }else if(last == 2){
                    if(mp[num] >= 2){
                        res += 2;
                        last = 2;
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