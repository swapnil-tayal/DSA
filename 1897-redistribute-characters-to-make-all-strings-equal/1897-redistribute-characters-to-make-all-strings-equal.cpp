class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        if(words.size() == 1) return 1;
        vector<int> a(26);
        for(auto &i: words){
            for(auto j: i){
                a[j-'a']++; 
            }
        }
        int prev = 0;
        for(int i=0; i<26; i++){
            if(a[i] % words.size() !=  0) return false;
        }
        return true;
    }
};