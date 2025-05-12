class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        vector<int> ans;
        map<int,int> mp;
        for(auto i: digits) mp[i]++;
        for(int i=100; i<1000; i++){
            if(i%2 == 1) continue;
            int x = i;
            int f = 0;
            map<int,int> mp2;
            while(x > 0){
                mp2[x%10]++;
                x = x/10;
            }
            for(auto k: mp2){
                if(k.second > mp[k.first]) f = 1;
            }
            if(f == 0) ans.push_back(i);
        }
        return ans;
    }
};