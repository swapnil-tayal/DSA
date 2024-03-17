class Solution {
public:
    int minimumDeletions(string word, int k) {
        
        map<char,int> mp;
        for(auto &i: word) mp[i]++;
        
        vector<int> a;
        for(auto i: mp) a.push_back(i.second);
        sort(a.begin(), a.end());
        
        int ans = word.size();
        int prev = 0;
        for(int i=0; i<a.size(); i++){
            
            int extra = 0;
            int currMin = a[i] + k;
            for(int j=i; j<a.size(); j++){
                if(a[j] > currMin) extra += a[j] - currMin;  
            }
            ans = min(ans, extra+prev);
            prev += a[i];
        }
        return ans;
    }
};