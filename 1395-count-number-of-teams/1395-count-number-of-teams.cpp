class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size();
        vector<int> greaterRight(n, 0);
        vector<int> greaterLeft(n, 0);
        
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=i+1; j<n; j++){
                if(rating[j] > rating[i]) cnt++;
            }
            greaterRight[i] = cnt;
        }
        for(int i=n-1; i>=0; i--){
            int cnt = 0;
            for(int j=i-1; j>=0; j--){
                if(rating[j] > rating[i]) cnt++;
            }
            greaterLeft[i] = cnt;
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(rating[i] < rating[j]){
                    ans += greaterRight[j];
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            for(int j=i-1; j>=0; j--){
                if(rating[i] < rating[j]){
                    ans += greaterLeft[j];
                }
            }
        }
        return ans;
    }
};