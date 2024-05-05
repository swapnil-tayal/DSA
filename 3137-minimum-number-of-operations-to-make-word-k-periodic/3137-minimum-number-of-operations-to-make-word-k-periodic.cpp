class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        
        map<string,int> mp;
        int n = word.size();
        
        int i = 0;
        while(i < n){
            
            int next = i+k;
            string str = "";
            while(i < next){
                str += word[i];
                i++;
            }
            mp[str]++;
        }
        
        int maxi = 0;
        for(auto i: mp){
            maxi = max(maxi, i.second);
        }
        return (n/k) - maxi;
    }
};