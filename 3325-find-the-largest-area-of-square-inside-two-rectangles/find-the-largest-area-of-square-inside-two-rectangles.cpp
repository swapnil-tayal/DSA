class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        
        int n = bottomLeft.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){

                int minimum_x = max(bottomLeft[i][0], bottomLeft[j][0]);
                int maximum_x = min(topRight[i][0], topRight[j][0]);
                int minimum_y = max(bottomLeft[i][1], bottomLeft[j][1]);
                int maximum_y = min(topRight[i][1], topRight[j][1]);

                if(minimum_x < maximum_x and minimum_y < maximum_y){
                    long long len = min(maximum_x - minimum_x, maximum_y - minimum_y);
                    ans = max(ans, len*len);
                }
            }
        }
        return ans;
    }
};