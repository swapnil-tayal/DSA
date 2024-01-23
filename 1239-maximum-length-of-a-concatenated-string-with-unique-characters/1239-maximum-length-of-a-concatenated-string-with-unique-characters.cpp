class Solution {
public:
    
    void f(int i, vector<string> &arr, vector<int> &freq, int &ans){
        
        if(i == arr.size()){
            
            int cnt = 0;
            for(auto &k: freq){
                if(k > 1) return;
                else cnt += k;
            }
            ans = max(ans, cnt);
            return;
        }
        
        for(auto &k: arr[i]){
            freq[k-'a']++;
        }
        f(i+1, arr, freq, ans);
        for(auto &k: arr[i]){
            freq[k-'a']--;
        }
        f(i+1, arr, freq, ans);
        return;
    }
    
    int maxLength(vector<string>& arr) {
        
        vector<int> freq(26, 0);
        int ans = 0;
        f(0, arr, freq, ans);
        return ans;
    }
};