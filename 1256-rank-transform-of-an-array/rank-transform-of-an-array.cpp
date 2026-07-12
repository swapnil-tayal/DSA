class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        map<int,int> mp;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(mp.find(temp[i]) == mp.end())
            mp[temp[i]] = ++cnt;
        }
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};