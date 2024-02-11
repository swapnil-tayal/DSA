class Solution {
public:
    
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
            if(j == needle.size()) ans.push_back(i-needle.size()+1);
        }
        return ans;
    }
    
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        
        string needle, haystack;
        
        for(auto i: pattern){
            if(i == -1) needle += '2';
            else if(i == 1) needle += '1';
            else needle += '0';
        }
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]) haystack += '1';
            else if(nums[i] == nums[i+1]) haystack += '0';
            else haystack += '2';
        }
        // cout<<needle<<'\n'<<haystack<<'\n';
        vector<int> ans = search(needle, haystack);
        return ans.size();
    }
};