class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int,int>> q;
        q.push({sr, sc});
        
        int row[] = {1,0,-1,0};
        int col[] = {0,1,0,-1};
        int intialColor = image[sr][sc];
        image[sr][sc] = color;
        
        if(color == intialColor) return image;
        
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++){
                
                int newi = x + row[k];
                int newj = y + col[k];
                
                if(newi >= 0 and newj >= 0 and newi < n and newj < m and image[newi][newj] == intialColor){
                    
                    image[newi][newj] = color;
                    q.push({newi, newj});
                }
            }
        }
        return image;
    }
};