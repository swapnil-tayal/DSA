class Solution {
public:

    int f(vector<int> &a, int mid, int k){

        int cnt = 0;
        int i = 0;
        while(i < a.size()){
            if(a[i] <= mid){
                cnt++;
                i += 2;
            }else i += 1;
        }
        return (cnt >= k);
    }   

    int minCapability(vector<int>& nums, int k) {
        
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        int ans = e;

        while(s <= e){
            int mid = (s+e)/2;
            if(f(nums, mid, k)){
                ans = mid;
                e = mid-1;
            }else s = mid+1;
        }
        return ans;
    }
};