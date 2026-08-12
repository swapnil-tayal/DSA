class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        vector<int> suf(n, 0);

        int ind = m-1;
        int len = 0;
        for(int i=n-1; i>=0; i--){
            suf[i] = len;
            if(ind >= 0 && word2[ind] == word1[i]){
                len++;
                ind--;
            }
        }

        ind = 0;
        vector<int> ans;
        int skip = 0;
        
        for(int i=0; i<n; i++){

            if(ind == m) break;
            if(word2[ind] == word1[i]){
                ans.push_back(i);
                ind++;

            }else if(!skip && suf[i] >= m-1-ind){
                ans.push_back(i);
                ind++;
                skip = 1;
            }
        }
        if(ind == m) return ans;
        return {};
    }
};