class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        int j = 0;
        int i = 0;
        int cnt = 0;
        map<int,int> mp;

        while(j < n){
            
            mp[fruits[j]]++;
            
            if(mp.size() <= 2){
                cnt = max(cnt, j-i+1);
                j++;
            }
            else{
                while(i < n && mp.size() > 2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                    i++;
                }
                if(mp.size() <= 2) cnt = max(cnt, j-i+1);
                j++;
            }
        }
        return cnt;
    }
};