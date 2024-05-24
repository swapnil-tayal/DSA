class Solution {
    vector<int> score;
    int ans;
public:
    
    void f(int i, vector<string> &words, map<char,int> &mp, int sum){
        
        if(i == words.size()){
            ans = max(ans, sum);
            return;
        }
        // pick
        map<char,int> mp2 (mp.begin(), mp.end());
        int check = 0;
        int value = 0;
        for(auto &k: words[i]){
            if(mp2[k] > 0){
                mp2[k]--;
                value += score[k-'a'];
            }
            else check = 1;
        }
        
        if(check == 0) f(i+1, words, mp2, sum + value);
        f(i+1, words, mp, sum);
        return;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        this->score = score;
        this->ans = 0;
        map<char,int> mp;
        for(auto &i: letters) mp[i]++;
        int sum = 0;
        f(0, words, mp, sum);
        return ans;
    }
};