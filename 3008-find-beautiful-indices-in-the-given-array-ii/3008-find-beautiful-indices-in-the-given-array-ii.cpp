class Solution {
public:
    
    vector<int> ans(vector<int> &arr1, vector<int> &arr2, int k){
        
        vector<int> ans;
        for(auto &i: arr1){
            
            int ind1 = lower_bound(arr2.begin(), arr2.end(), i-k) - arr2.begin();
            int ind2 = lower_bound(arr2.begin(), arr2.end(), i+k) - arr2.begin();
            if(ind1 < arr2.size() and abs(arr2[ind1] - i) <= k) ans.push_back(i);
            else if(ind2 < arr2.size() and abs(arr2[ind2] - i) <= k) ans.push_back(i);
        }
        return ans;
    }
    
    vector<int> lpsFind(string needle){
        int n = needle.size();
        vector<int> lps(n, 0);
        
        int prevLps = 0;
        int i = 1;
        while(i < n){
            if(needle[i] == needle[prevLps]){
                lps[i] = prevLps+1;
                i++;
                prevLps++;
            }else{
                if(prevLps == 0){
                    lps[i] = 0;
                    i++;
                }else{
                    prevLps = lps[prevLps-1];
                }
            }
        }
        return lps;
    }
    
    vector <int> search(string needle, string haystack){
       
        if(needle.size() == 0) return {-1};
        vector<int> lps = lpsFind(needle);
        vector<int> ans;
        
        int i = 0; // haystack
        int j = 0; // needle
        
        while(i < haystack.size()){
            
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }else{
                if(j == 0){
                    i++;
                }else{
                    j = lps[j-1];
                }
            }
            if(j == needle.size()) ans.push_back(i-needle.size());
        }
        return ans;
    }
    
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        int n = s.size();
        if(n < a.size() || n < b.size()) return {};
        
        vector<int> arr1 = search(a, s);
        vector<int> arr2 = search(b, s);
        
        return ans(arr1, arr2, k);
    }
};