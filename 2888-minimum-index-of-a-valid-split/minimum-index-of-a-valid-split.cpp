class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int> mp;
        int maxi = 0;
        int val = 0;
        for(auto &i: nums){
            mp[i]++;
            if(mp[i] > maxi){
                maxi = mp[i];
                val = i;
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt += (nums[i] == val);
            // cout<<cnt<<' '<<(i+1)<<' '<<maxi-cnt<<' '<<(n-i-1)<<'\n';
            if(cnt > (i+1)/2 and (maxi-cnt) > (n-i-1)/2){
                return i;
            }
        }
        return -1;
    }
};