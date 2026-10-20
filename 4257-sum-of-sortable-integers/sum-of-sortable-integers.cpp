class Solution {
public:

    vector<int> divisors(int n) {
        vector<int> ans;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                ans.push_back(i);
                if(i != n / i) {
                    ans.push_back(n / i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    int f(vector<int> &nums, int k){

        vector<int> a;
        int n = nums.size();
        for(int i=0; i<n; i+=k){
            vector<int> temp;
            for(int j=i; j<i+k; j++){
                if(temp.size() and temp.back() == nums[j]) continue;
                temp.push_back(nums[j]);
            }
            if(temp.size() > 1 && temp[0] == temp.back()) temp.pop_back();
            // for(auto &i: temp) cout<<i<<' ';
            // cout<<'\n';
            int x = temp.size();
            vector<int> newTemp;
            int ind = min_element(temp.begin(), temp.end()) - temp.begin();
            for(int j=ind; j<ind+x; j++){
                a.push_back(temp[j % x]);
            }
        }
        // for(auto &i: a) cout<<i<<' ';
        // cout<<'\n';
        return is_sorted(a.begin(), a.end());
    }

    int sortableIntegers(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> a = divisors(n);
        int sum = 0;
        for(auto &i: a){
            cout<<i<<'\n';
            if(f(nums, i)){
                sum += i;
                // cout<<i<<'\n';
            }
        }
        return sum;
    }
};