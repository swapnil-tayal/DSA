class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char, int> mp;
        for(auto &i: text){
            mp[i]++;
        }
        int ans = 1e9;
        string temp = "balloon";
        int findAll = 0;
        for(auto &i: temp){
            if(mp.find(i) == mp.end()) return 0;
        }
        if(mp['l'] <= 1 || mp['o'] <= 1) return 0;
        for (auto &i : mp) {
            if (temp.find(i.first) != string::npos) {
                if(i.first == 'l' || i.first == 'o'){
                    i.second /= 2;
                }
                ans = min(ans, i.second);
            }
        }
        return ans == 1e9 ? 0 : ans;
    }
};