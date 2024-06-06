class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        map<int,int> mp;
        for(auto i: hand){
            mp[i]++;
        }
        
        while(mp.size()){
            
            int mini = mp.begin()->first;
            int cnt = 0;
            for(int i=0; i<groupSize; i++){
                
                
                if(mp.find(mini+i) == mp.end()){
                    return false;
                }else{
                
                    mp[mini+i]--;
                    if(mp[mini+i] == 0) mp.erase(mini+i);
                    cnt++;
                }
            }
            if(cnt != groupSize) return false;
        }
        return true;
    }
};