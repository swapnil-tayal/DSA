class Solution {
public:

    int f(vector<int> &a, int k, vector<vector<int>> &queries){

        int n = a.size();
        vector<int> b(n, 0);
        for(int i=0; i<=k; i++){
            int s = queries[i][0];
            int e = queries[i][1];
            int val = queries[i][2];
            b[s] -= val;
            if(e+1 < n) b[e+1] += val;
        }
        for(int i=1; i<n; i++){
            b[i] = b[i-1]+b[i];
        }
        for(int i=0; i<n; i++){
            if(a[i] + b[i] > 0){
                return 0;
            }
        }
        return 1;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();

        int s = 0;
        int e = queries.size()-1;
        int ans = -1;
        int fl = 0;
        for(auto i: nums){
            if(i != 0) fl = 1;
        }
        if(fl == 0) return 0;

        while(s <= e){
            int mid = (s+e)/2;
            if(f(nums, mid, queries)){
                ans = mid+1;
                e = mid-1;
            }else s = mid+1;
        }
        return ans;
    }
};