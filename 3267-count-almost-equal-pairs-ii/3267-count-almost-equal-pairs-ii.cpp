class Solution {
public:
    
    unordered_set<int> f(int num){
        
        string str = to_string(num);
        
        while(str.size() < 7) str = "0" + str;
        int n = str.size();
        unordered_set<int> st;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                string s = str;
                swap(s[i], s[j]);
                st.insert(stoi(s));
                
                for(int k=0; k<n; k++){
                    for(int l=k+1; l<n; l++){
                        swap(s[k], s[l]);
                        st.insert(stoi(s));
                        swap(s[k], s[l]);
                    }
                }
                swap(s[i], s[j]);
            }
        }
        return st;
        
    }
    
    int countPairs(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++) mp[nums[i]]++;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            
            unordered_set<int> st = f(nums[i]);
            for(auto &k: st){
                if(mp.find(k) != mp.end()){
                    if(k == nums[i]) ans = ans + (mp[k]-1);
                    else ans = ans + mp[k];
                }
            }
        }
        return ans/2;
    }
};