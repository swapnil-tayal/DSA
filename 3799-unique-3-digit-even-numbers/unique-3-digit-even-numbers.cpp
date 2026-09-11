class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        int n = digits.size();
        map<int,int> mp;
        for(auto &i: digits) mp[i]++;
        int cnt = 0;

        for(int i=100; i<1000; i+=2){

            map<int,int> mp2;
            for(auto &k: to_string(i)) mp2[k-'0']++;
            int f = 1;
            for(auto &k: mp2){
                if(mp[k.first] < k.second) f = 0;
            }
            if(f) cnt++;
        }
        return cnt;
    }
};