class Solution {
public:
    long long countCompleteDayPairs(vector<int>& arr) {
        
        int n = arr.size();
        map<int,int> mp;
        
        for(auto &i: arr){
            i = i%24;
            mp[i]++;
        }
        long long cnt = 0;
        
        for(auto i: arr){
            
            int req = (24-i) % 24;
            // cout<<req<<' '<<i<<' '<<mp[req]<<'\n';
            if(req == i){
                cnt += mp[req]-1;
            }else{
                cnt += mp[req];
            }
        }
        return cnt/2;
    }
};