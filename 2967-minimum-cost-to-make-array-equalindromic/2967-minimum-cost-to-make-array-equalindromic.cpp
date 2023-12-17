class Solution {
public:
    
    int isPali(int n){
        string str = to_string(n);
        string str2 = str;
        reverse(str.begin(), str.end());
        return str == str2;
    }
    
    pair<int,int> neraPali(int n){
        int val = n;
        int num1 = -1;
        int num2 = -1;
        while(val >= 0){   
            if(isPali(val)){
                num1 = val;
                break;
            }else val--;
        }
        val = n;
        while(val <= 1e9){
            if(isPali(val)){
                num2 = val;
                break;
            }else val++;
        }
        return {num1, num2};
    }
    
    long long minimumCost(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        
        pair<int,int> p = neraPali(nums[n/2]);
        long long ans1 = 0;
        long long ans2 = 0;
        int pali1 = p.first;
        for(auto &i: nums){
            ans1 += abs(i - pali1);
        }
        int pali2 = p.second;
        for(auto &i: nums){
            ans2 += abs(i - pali2);
        }
        return min(ans1, ans2);
    }
};