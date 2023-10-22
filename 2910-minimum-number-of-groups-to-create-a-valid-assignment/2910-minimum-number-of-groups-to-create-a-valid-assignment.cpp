class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        
        map<int,int> mp;
        for(auto i: nums) mp[i]++;
        
        int mini = 1e9;
        vector<int> freq;
        for(auto i: mp){
            mini = min(mini, i.second);
            freq.push_back(i.second);
        }
        int ans = 1e9;
        
        for(int i=1; i<=mini; i++){
            
            int cnt = 0;
            for(int k=0; k<freq.size(); k++){
                
                if(freq[k] % (i+1) == 0) cnt += freq[k] / (i+1);
                else{
                    int f = 0;
                    int x = freq[k] / (i+1);
                    for(int j=x; j>=0; j--){
                        int e = freq[k] - (j*(i+1));
                        if(e % i == 0){
                            cnt += j + (e/i);
                            f = 1;
                            break;
                        }
                    }
                    if(f == 0) cnt = 1e9;
                }
            }
            ans = min(ans, cnt);
        }
        return max(ans, 1);
    }
};