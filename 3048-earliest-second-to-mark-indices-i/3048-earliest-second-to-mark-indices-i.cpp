class Solution {
    int n,m;
public:
    
    int f(int mid, vector<int> &nums, vector<int> &changeIndices){
        
        map<int,int> mp;
        set<int> st;
        for(int i=0; i<=mid; i++){
            
            if(mp.find(changeIndices[i]) == mp.end()){
                mp[changeIndices[i]] = i;
                st.insert(i);
            
            }else{
                int prevInd = mp[changeIndices[i]];
                st.erase(prevInd);
                st.insert(i);
                mp[changeIndices[i]] = i;
            }
        }
        if(st.size() < n) return 0;
        // cout<<st.size()<<' ';
        
        int currPoints = 0;
        
        for(int i=0; i<=mid; i++){
            
            if(st.count(i) == 0) currPoints++;
            else{
                
                // cout<<i<<' ';
                int ind = changeIndices[i]-1;
                if(currPoints >= nums[ind]){
                    currPoints -= nums[ind];
                    
                }else return 0;
            }
        }
        return 1;
    }
    
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        
        m = changeIndices.size();
        n = nums.size();
        long long sum = 0;
        for(auto &i: nums) sum += i;
        
        if(sum + n > m) return -1;
        
        int s = 0;
        int e = m-1;
        int ans = -2;
        
        // cout<<f(5, nums, changeIndices)<<' ';
        
        while(s <= e){
            
            int mid = (s+e)/2;
            if(f(mid, nums, changeIndices)){
                ans = mid;
                e = mid-1;
            }else s = mid+1;
        }
        return ans+1;
    }
};