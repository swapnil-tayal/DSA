class Solution {
    int mod = (1e9+7);
public:
    
    int fast_pow(int a, int p) {
      int res = 1;
      while (p) {
        if (p % 2 == 0) {
          a = a * 1ll * a % mod;
          p /= 2;
        } else {
          res = res * 1ll * a % mod;
          p--;
        }
      }
      return res;
    }
    
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        
        if(m == 1) return nums;
        
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        for(int i=0; i<n; i++){
            pq.push({ nums[i], i });
        }
        int maxi = *max_element(nums.begin(), nums.end());
        
        while(k && 1ll * pq.top().first * m <= maxi){
            k--;
            pq.push({ (pq.top().first * m) % mod , pq.top().second });
            pq.pop();
        }
        
        long long pow = fast_pow(m, k/n);
        
        while(!pq.empty()){
            
            int val = pq.top().first;
            int ind = pq.top().second;
            if(k % n != 0){
                k--;
                nums[ind] = (long long)( 1ll * ((m * pow) % mod) * val ) % mod;
            }
            else nums[ind] = (long long)( 1ll * pow * val ) % mod;
            pq.pop();
        }
        return nums;
    }
};


