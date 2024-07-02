class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> mp;
        map<int,int> mp2;
        for(auto i: nums1){
            mp[i]++;
        }
        for(auto i: nums2){
            mp2[i]++;
        }
        vector<int> arr;
        for(auto i: mp){
            int k = min(mp[i.first], mp2[i.first]);
            if(k >= 0){
                while(k--){
                    arr.push_back(i.first);
                }
            }
        }
        return arr;
    }
};