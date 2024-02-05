class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        
        int n = word.size();
        for(int i=k; i<n; i+=k){
            
            if(word.substr(0, n-i) == word.substr(i, n)){
                return i/k;
            }
        }
        return (n+k-1)/k;
    }
};