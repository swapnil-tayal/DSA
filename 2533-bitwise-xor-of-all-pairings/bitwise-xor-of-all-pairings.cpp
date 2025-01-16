class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        vector<int> a(85,0);
        for(auto &i: nums1){
            int ind = 0;
            while(i > 0){
                if(i%2 == 1) a[ind] += (1) * (nums2.size() % 2);
                ind++;
                i = i/2; 
            }
        }
        // for(auto i: a) cout<<i<<' ';
        // cout<<'\n';
        for(auto &i: nums2){
            int ind = 0;
            while(i > 0){
                if(i%2 == 1) a[ind] += (1) * (nums1.size() % 2);
                ind++;
                i = i/2; 
            }
        }        
        // for(auto i: a) cout<<i<<' ';
        // cout<<'\n';
        int ans = 0;
        int ind = 0;
        for(auto &i: a){
            if(i%2 == 1) ans += pow(2, ind);
            ind++;
        }
        return ans;
    }
};
