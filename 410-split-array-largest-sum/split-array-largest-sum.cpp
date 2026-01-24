class Solution {
    vector<int> pre;
    int k;
public:

    int f(int mid, vector<int> &nums){

        int n = nums.size();
        int sum = 0;
        int cnt = 1;
        for(int i=0; i<n; i++){
            
            if(sum + nums[i] > mid){
                cnt++;
                if(cnt > k || nums[i] > mid) return 0;
                sum = nums[i];

            }else sum += nums[i];
        }
        return 1;
    }

    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        this->k = k;
        int s = 1;
        int e = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;

        while(s <= e){

            int mid = (s+e)/2;
            if(f(mid, nums)){

                ans = mid;
                e = mid-1;

            }else s = mid+1;
        }
        return ans;
    }
};