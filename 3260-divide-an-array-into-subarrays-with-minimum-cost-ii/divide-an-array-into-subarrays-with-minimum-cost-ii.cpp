class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        
        int n = nums.size();
        multiset<int> small, rest;
        int i = 1;
        int j = 1;
        long long ans = LONG_MAX;
        long long sum = 0;

        while(j < n){

            if(j-i+1 <= dist){
                small.insert(nums[j]);
                sum += nums[j];
                j++;
            }
            else {
                if(nums[j] < *small.rbegin()){
                    sum += nums[j];
                    small.insert(nums[j]);
                } else rest.insert(nums[j]);

                while(small.size() > k-2){
                    sum -= *small.rbegin();
                    rest.insert(*small.rbegin());
                    small.erase(small.find(*small.rbegin()));
                }
                while(small.size() < k-1 and rest.size()){
                    sum += *rest.begin();
                    small.insert(*rest.begin());
                    rest.erase(rest.find(*rest.begin()));
                }
                ans = min(ans, sum);
                if(small.find(nums[i]) != small.end()) {
                    sum -= nums[i];
                    small.erase(small.find(nums[i]));
                }
                else if(rest.find(nums[i]) != rest.end()){
                    rest.erase(rest.find(nums[i]));
                }
                i++;
                j++;
            }
        }
        return ans + nums[0];
    }
};