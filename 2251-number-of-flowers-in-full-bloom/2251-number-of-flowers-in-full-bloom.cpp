class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        vector<int> str, end;
        for(auto i: flowers) str.push_back(i[0]);
        for(auto i: flowers) end.push_back(i[1]);
        sort(end.begin(), end.end());
        sort(str.begin(), str.end());
        
        int n = people.size();
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            
            int k = people[i];
            int ind1 = upper_bound(str.begin(), str.end(), k) - str.begin();
            int ind2 = lower_bound(end.begin(), end.end(), k) - end.begin();
            ans.push_back(ind1 - ind2);
            
        }
        return ans;
    }
};