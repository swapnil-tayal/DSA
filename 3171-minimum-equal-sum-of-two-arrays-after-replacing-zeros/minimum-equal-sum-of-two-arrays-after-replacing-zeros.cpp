class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        long long sum1 = 0;
        int z1 = 0;
        long long sum2 = 0;
        int z2 = 0;
        for(auto &i: nums1){
            sum1 += i;
            z1 += (i==0);
        }
        for(auto &i: nums2){
            sum2 += i;
            z2 += (i==0);
        }
        if(sum1 > sum2){
            swap(sum1, sum2);
            swap(z1, z2);
        }
        cout<<sum1<<' '<<z1<<'\n';
        cout<<sum2<<' '<<z2<<'\n';
        if(sum1 == sum2){
            if(z1 == 0 && z2 == 0) return sum1;
            if(z1 == 0 || z2 == 0) return -1;
            if(z1 > z2) return sum1+z1;
            else return sum2+z2;
        }
        if(z1 == 0) return -1;
        if(z2 == 0){
            if(sum1 + z1 > sum2) return -1;
            else return sum2;
        }
        return max(sum1+z1, sum2+z2);
    }
};