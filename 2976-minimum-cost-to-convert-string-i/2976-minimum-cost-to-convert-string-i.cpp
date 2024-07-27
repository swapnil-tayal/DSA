class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        
        int n = original.size();
        vector<vector<long long>> grid(26, vector<long long>(26, 1e11));
        
        for(int i=0; i<n; i++){
            grid[original[i]-'a'][changed[i]-'a'] = min(grid[original[i]-'a'][changed[i]-'a'], (long long)cost[i]);
        }
        
        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    grid[i][j] = min(grid[i][j], (long long)grid[i][k] + (long long)grid[k][j]);
                }
            }
        }
        for(int i=0; i<26; i++) grid[i][i] = 0;
        
        long long ans = 0;
        for(int i=0; i<source.size(); i++){
            
            if(grid[source[i]-'a'][target[i]-'a'] != 1e11){
                ans += grid[source[i]-'a'][target[i]-'a'];
                
            }else return -1;
        }
        return ans;
    }
};