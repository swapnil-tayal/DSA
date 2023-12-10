class Solution{
    int mod = 1e9+7;
public:
    
    int pow(int n){
        int k = 1;
        for(int i=0; i<n; i++){
            k = (k*2) % mod;
        }return k;
    }
    
    int numberOfGoodPartitions(vector<int>& nums) {
        
        int n = nums.size();
        map<int,pair<int,int>> mp;
        
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]].first = i;
                mp[nums[i]].second = i;
            
            }else mp[nums[i]].second = i;
        }
        
        int currMax = 0;
        int mini = 0;
        int cnt = 1;
        for(int i=0; i<n; i++){
            if(i > currMax){
                cnt++;
                mini = i;
                currMax = max(currMax, mp[nums[i]].second);
            }else{
                currMax = max(currMax, mp[nums[i]].second);
            }
        }
        return pow(cnt-1);
    }
};