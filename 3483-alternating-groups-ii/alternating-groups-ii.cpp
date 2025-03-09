class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        for(int i=0; i<k-1; i++){
            colors.push_back(colors[i]);
        }
        
        int i = 0;
        int ans = 0;
        int cnt = 0;
        int n = colors.size();
        while(i < n-1){
            cnt++;
            if(colors[i] == colors[i+1]){
                ans += max(0, cnt-k+1);
                cnt = 0;
            }
            i++;
        }
        if(colors[n-2] != colors[n-1]){
            cnt++;
            ans += max(0, cnt-k+1);
        }
        return ans;
    }
};