bool cmp(vector<int> &a1, vector<int> &a2){
    if(a1[0] == a2[0]) return a1[1] > a2[1];
    else return a1[0] < a2[0];
}

class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& a) {
        
        int n = a.size();
        sort(a.begin(), a.end(),cmp);
        vector<int> heigth;
        heigth.push_back(a[0][1]);
        
        for(int i=1; i<n; i++){
            
            if(a[i][1] > heigth.back()) heigth.push_back(a[i][1]);
            else{
                
                int ind = lower_bound(heigth.begin(), heigth.end(), a[i][1]) - heigth.begin();
                heigth[ind] = a[i][1];
            }
        }
        return heigth.size();
    }
};