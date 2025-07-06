class FindSumPairs {
    map<int,int> mp;
    vector<int> nums1, nums2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto i: nums2){
            mp[i]++;
        }
        this->nums1 = nums1;
        this->nums2 = nums2;
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--;
        nums2[index] += val; 
        mp[nums2[index]]++;
    }
    
    int count(int tot) {

        int ans = 0;
        for(int i=0; i<nums1.size(); i++){
            if(mp.count(tot - nums1[i])){
                ans += mp[tot-nums1[i]];
            }
        }
        return ans;
    }
};