class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        int n = nums.size();
        map<int,vector<int>> mp;
        int ind = 0;

        vector<int> st;
        map<int,int> mp2;
        for(int i=0; i<n; i++){
            
            if(st.size() == 0 || arr[i] - st.back() <= limit){
                mp2[arr[i]] = ind;
                st.push_back(arr[i]);
                
            }else{
                mp[ind] = st;
                st.clear();
                st.push_back(arr[i]);
                ind++;
                mp2[arr[i]] = ind;
            }
        }   
        if(st.size()) mp[ind] = st;

        for(auto &i: mp){
            reverse(i.second.begin(), i.second.end());
        }

        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            ans[i] = mp[mp2[nums[i]]].back();
            mp[mp2[nums[i]]].pop_back();
        }
        return ans;
    }
};