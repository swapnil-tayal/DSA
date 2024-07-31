class Solution{
    
    int f(int i, vector<vector<int>> &books, int shelfWidth, vector<int> &dp){
        
        if(i == books.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        int currMax = 0;
        int currWidth = 0;
        int ans = 1e9;
        
        for(int k=i; k<books.size(); k++){
            
            currMax = max(currMax, books[k][1]);
            currWidth += books[k][0];
            if(currWidth <= shelfWidth){
                ans = min(ans, currMax + f(k+1, books, shelfWidth, dp));
            
            }else break;
        }
        return dp[i] = ans;
    }
    
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
        vector<int> dp(books.size(), -1);
        return f(0, books, shelfWidth, dp);
    }
};