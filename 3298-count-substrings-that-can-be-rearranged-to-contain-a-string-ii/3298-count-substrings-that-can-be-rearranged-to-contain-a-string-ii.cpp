class Solution{
    
    vector<int> mp2;
    vector<int> mp1;
    
public:
    
    int f(){
        for(int i=0; i<26; i++){
            if(mp1[i] < mp2[i]) return 0;
        }
        return 1;
    }
    
    long long validSubstringCount(string word1, string word2) {
        
        mp2.resize(26, 0);
        mp1.resize(26, 0);
        
        for(auto &i: word2) mp2[i-'a']++;
        
        int i = 0;
        int j = 0;
        int n = word1.size();
        long long cnt = 0;
        
        while(j < n){
            
            mp1[word1[j]-'a']++;
            if(f() == 0) j++;
            else{
                
                while(f()){
                    mp1[word1[i]-'a']--;
                    cnt += n-j;
                    i++;
                }
                j++;
            }
        }
        return cnt;
    }
};