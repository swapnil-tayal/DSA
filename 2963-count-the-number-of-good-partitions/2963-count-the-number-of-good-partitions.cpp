class Solution{
    vector<int> pow;
    int mod = 1e9+7;
public:
    
    void f(){
        int k = 1;
        for(int i=0; i<100001; i++){
            pow.push_back(k);
            k = (k*2) % mod;
        }
    }
    
    Solution(){
        f();
    }
    
    int numberOfGoodPartitions(vector<int>& nums) {
        
        int n = nums.size();
        int rem = 0;
        vector<vector<int>> inter;
        
        map<int,pair<int,int>> mp;
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]].first = i;
                mp[nums[i]].second = i;
            
            }else mp[nums[i]].second = i;
        }
        
        int currMax = 0;
        int mini = 0;
        for(int i=0; i<=n; i++){
            if(i > currMax){
                inter.push_back({ mini, currMax });
                if(i == n) break;
                mini = i;
                currMax = max(currMax, mp[nums[i]].second);
            }else{
                currMax = max(currMax, mp[nums[i]].second);
            }
        }
        return pow[inter.size()-1];
    }
};