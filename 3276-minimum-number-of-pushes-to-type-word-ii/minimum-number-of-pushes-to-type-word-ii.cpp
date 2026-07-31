class Solution {
public:
    int minimumPushes(string word) {
        
        unordered_map<int,int> mp;
        for(auto &i: word){
            mp[i]++;
        }
        vector<int> arr;
        for(auto i: mp){
            arr.push_back(i.second);
        }
        sort(arr.rbegin(), arr.rend());
        int rem1 = 8;
        int rem2 = 8;
        int rem3 = 8;
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            int x = arr[i];
            if(rem1-- > 0) ans += x;
            else if(rem2-- > 0) ans += 2*x;
            else if(rem3-- > 0) ans += 3*x;
            else ans += 4*x;
        }
        return ans;
    }
};