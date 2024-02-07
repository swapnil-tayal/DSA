class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> mp;
        for(auto i: s) mp[i]++;
        
        priority_queue<pair<int, char>> pq;
        for(auto [i, j]: mp) pq.push({j, i});
        
        string ans = "";
        while(!pq.empty()){
            
            int n = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            for(int i=0; i<n; i++){
                ans += c;
            }
        }
        return ans;
    }
};