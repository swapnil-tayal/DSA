class Solution {
public:
    
    int f(int size, vector<int> &nums, long long int k){
        int n = nums.size();
        vector<long long> pre(n, 0);
        vector<long long> suf(n, 0);
        
        pre[0] = nums[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        suf[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suf[i] = suf[i+1] + nums[i];
        }
        int i = 0;
        int j = size-1;
        while(j < n){
            
            int med = i + (j-i+1)/2;
            long long last = 0;
            if(med-1 >= 0) last = pre[med-1];
            if(i-1 >= 0) last -= pre[i-1];
            long long next = 0;
            if(med+1 < n) next = suf[med+1];
            if(j+1 < n) next -= suf[j+1];
            
            long long reqPrev = (long long)nums[med]*(long long)(med-i) - last;
            long long reqNext = next - (long long)nums[med]*(long long)(j-med);
    
            if(reqPrev + reqNext <= k) return true;
            j++;
            i++;
        }
        return false;
    }
    
    int maxFrequencyScore(vector<int>& nums, long long k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int s = 1;
        int e = n;
        int ans = -1;
        while(s <= e){
            int mid = (s+e)/2;
            if(f(mid, nums, k)){
                ans = mid;
                s = mid+1;
            }else e = mid-1;
        }
        return ans;
    }
};