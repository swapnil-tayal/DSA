class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        set<int> st(nums.begin(), nums.end());
        int unq = st.size();
        int n = nums.size();

        int i = 0;
        int j = 0;
        map<int,int> mp;
        int ans = 0;

        while(j < n){

            mp[nums[j]]++;
            if(mp.size() < unq) j++;
            else{

                while(mp.size() == unq){
                    ans += (n-j);
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0) mp.erase(nums[i]);
                    i++;
                }
                if(mp.size() == unq) ans += (n-j);
                j++;
            }
        }
        return ans;
    }
};