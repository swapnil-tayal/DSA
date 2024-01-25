class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        
        long long ans = 1e16;
        int n = nums.size();
        multiset<long long> l, r;
        
        k--;
        int i = 1;
        int j = 1;
        long long sum = 0;
        
        while(j < n){
            
            if(j-i+1 <= dist){
                l.insert(nums[j]);
                sum += nums[j];
                j++;
            }else{
                
                if(nums[j] < *l.rbegin()){
                    l.insert(nums[j]);
                    sum += nums[j];
                }else r.insert(nums[j]);
                
                while(l.size() >= k){
                    sum -= *l.rbegin();
                    r.insert(*l.rbegin());
                    l.erase(l.find(*l.rbegin()));
                }
                while(l.size() < k and r.size()){
                    sum += *r.begin();
                    l.insert(*r.begin());
                    r.erase(r.find(*r.begin()));
                }
                ans = min(ans, sum);
                
                // erase
                if(l.find(nums[i]) != l.end()){
                    sum -= nums[i];
                    l.erase(l.find(nums[i]));
                }else if(r.find(nums[i]) != r.end()){
                    r.erase(r.find(nums[i]));
                }
                i++;
                j++;
            }
        }
        return ans + nums[0];
    }
};