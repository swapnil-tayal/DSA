bool cmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.first < p2.first) return true;
    else return false;
}

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int,int>> arr;
        
        for(auto &i: nums){
            
            string str = "";
            int x = i;
            if(i == 0) str += char(mapping[0] + '0');
            while(x > 0){
                str += char(mapping[x%10] + '0');
                x = x/10;
            }
            reverse(str.begin(), str.end());
            arr.push_back({ stoi(str), i });
        }
        sort(arr.begin(), arr.end(), cmp);
        vector<int> res;
        for(auto i: arr){
            res.push_back(i.second);
        }
        return res;
    }
};