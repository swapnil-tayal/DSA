class Solution {
public:

    int rev(int num){

        string str = "";
        while(num > 0){
            str += to_string(num % 10);
            num = num / 10;
        }
        return stoi(str);
    }

    int minMirrorPairDistance(vector<int>& nums) {
        
        int mini = 1e9;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                mini = min(mini, i - mp[nums[i]]);
            }
            mp[rev(nums[i])] = i;
        }
        return mini == 1e9 ? -1 : mini;
    }
};