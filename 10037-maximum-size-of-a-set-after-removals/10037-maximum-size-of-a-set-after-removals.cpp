class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        map<int,int> mp1;
        map<int,int> mp2;
        
        for(auto &i: nums1) mp1[i]++;
        for(auto &i: nums2) mp2[i]++;
        
        int cnt1 = 0;
        int cnt2 = 0;
        
        for(auto &i: mp1){
            cnt1 += i.second-1;
            i.second = 1;
        }
        for(auto &i: mp2){
            cnt2 += i.second-1;
            i.second = 1;
        }
        
        map<int,int> mp;
        for(auto i: mp1){
            if(i.second) mp[i.first]++;
        }
        for(auto i: mp2){
            if(i.second) mp[i.first]++;
        }
        
        if(cnt1 >= n/2 and cnt2 >= n/2) return mp.size();
        
        for(auto &i: mp){
            if(i.second > 1){
                i.second = 1;
                if(cnt1 < n/2) cnt1++;
                else if(cnt2 < n/2) cnt2++;
            }
        }
        return mp.size() - max(0, n/2-cnt1) - max(0, n/2-cnt2);
    }
};