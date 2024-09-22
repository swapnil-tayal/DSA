class Solution{
    
    map<char,int> mp1;
    map<char,int> mp2;
    
public:
    
    int f(){
        for(auto i: mp2){
            if(mp1[i.first] < i.second) return 0;
        }
        return 1;
    }
    
    long long validSubstringCount(string word1, string word2) {
        
        for(auto &i: word2) mp2[i]++;
        
        int i = 0;
        int j = 0;
        int n = word1.size();
        long long cnt = 0;
        
        while(j < n){
            
            mp1[word1[j]]++;
            if(f() == 0) j++;
            else{
                
                while(f()){
                    mp1[word1[i]]--;
                    cnt += n-j;
                    i++;
                }
                j++;
            }
        }
        return cnt;
    }
};