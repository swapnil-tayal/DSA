class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        map<int,int> mp;
        for(auto &i: nums){
            mp[i]++;
        }
        int ans = 0;
        for(auto &i: mp){
            
            int cnt = 1e9;
            int x = i.second;
            
            for(int k=0; k<=x; k++){
                
                if(k%2 == 0 && (x-k)%3 == 0) cnt = min(cnt, k/2 + (x-k)/3);
                else if(k%3 == 0 && (x-k)%2 == 0) cnt = min(cnt, k/3 + (x-k)/2);
            }
            if(cnt == 1e9) return -1;
            else ans += cnt;
        }
        return ans;
    }
};