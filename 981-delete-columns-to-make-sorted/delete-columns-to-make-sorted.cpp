class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int m = strs[0].size();
        int n = strs.size();
        vector<string> arr(m);
         
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                arr[j].push_back(strs[i][j]);
            }
        }
        int cnt=0;
        for(auto i: arr){
            string s1 = i;
            sort(s1.begin(), s1.end());
            if(i != s1){
                cnt++;
            }
        }
        return cnt;
    }
};