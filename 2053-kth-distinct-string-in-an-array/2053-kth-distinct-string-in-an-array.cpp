class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        map<string,int> mp;
        for(auto i: arr) mp[i]++;
        
        for(auto i: arr){
            if(mp[i] == 1){
                if(k == 1) return i;
                else k--;
            }
        }
        return "";
    }
};