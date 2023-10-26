class Solution {
    const int mod = 1000000007;
public:
    
    int f(int num, set<int> &st, map<int,int> &mp){
        
        long long cnt = 0;
        
        if(mp.find(num) != mp.end()) return mp[num];
        
        for(auto i: st){
            if(num > i and num%i == 0 and st.count(num/i)){
                cnt = (cnt + ((long long)mp[num/i] * (long long)mp[i])) % mod;
            }
        }
        return mp[num] = (1 + cnt) % mod;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        int n = arr.size();
        set<int> st;
        for(auto i: arr) st.insert(i);
        
        long long ans = 0;
        map<int,int> dp;
        for(auto i: st){
            ans = (ans + f(i, st, dp)) % mod;
        }
        return ans;
    }
};