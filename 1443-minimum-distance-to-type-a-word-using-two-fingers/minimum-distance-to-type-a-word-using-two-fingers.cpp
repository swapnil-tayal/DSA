class Solution {
    unordered_map<char,vector<int>> mp;
    unordered_map<string, int> dp;
public:

    Solution(){
        char ch = 'A';
        for(int i=0; i<5; i++){
            for(int j=0; j<6; j++){
                mp[ch] = {i,j};
                ch++;
            }
        }
    }

    int findDis(char ch1, char ch2){

        if(ch1 == '-') return 0;
        auto a1 = mp[ch1];
        auto a2 = mp[ch2];
        return abs(a1[0] - a2[0]) + abs(a1[1] - a2[1]);

    }

    int f(int i, char other, string word){

        if(i == word.size()){
            return 0;
        }

        string str = to_string(i);
        str += '-';
        str += to_string(other);

        if(dp.find(str) != dp.end()) return dp[str];

        char curr = (i > 0) ? word[i-1] : '-';

        int ans1 = findDis(curr, word[i]) + f(i+1, other, word);
        int ans2 = findDis(other, word[i]) + f(i+1, curr, word);

        return dp[str] = min(ans1, ans2);
    }

    int minimumDistance(string word) {
        
        return f(0, '-', word);
    }
};