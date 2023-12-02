class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        map<char, int> mp;
        for(auto i: chars) mp[i]++;
        int cnt = 0;
        
        for(auto i: words){
            map<char, int> tempMp = mp;
            for(auto j: i){
                tempMp[j]--;
                if(tempMp[j] < 0){
                    cnt -= i.size();
                    break;
                }
            }cnt += i.size();
        }
        return cnt;
    }
};