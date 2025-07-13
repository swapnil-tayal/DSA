class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        
        int ind = p.size()-1;
        int ind2 = t.size()-1;
        int cnt = 0;
        while(ind2 >= 0 && ind >= 0){
            if(p[ind] <= t[ind2]){
                cnt++;
                ind2--;
            }
            ind--;
        }
        return cnt;
    }
};