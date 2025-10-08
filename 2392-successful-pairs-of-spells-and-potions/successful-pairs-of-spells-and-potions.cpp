class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;

        for(int i=0; i<n; i++){
            long long val = (success + (spells[i]-1)) / spells[i];
            int ind = lower_bound(potions.begin(), potions.end(), val) - potions.begin();
            ans.push_back(m - ind); 
        }
        return ans;
    }
};

// x*y >= z
// x >= z/y