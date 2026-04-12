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

        auto a1 = mp[ch1];
        auto a2 = mp[ch2];
        return abs(a1[0] - a2[0]) + abs(a1[1] - a2[1]);

    }

    int f(int i, int isF, int isS, char lastF, char lastS, string word){

        if(i == word.size()){
            return 0;
        }

        string str = to_string(i);
        str += '-';
        str += to_string(isF);
        str += '-';
        str += to_string(isS);
        str += '-';
        str += lastF;
        str += '-';
        str += lastS;

        if(dp.find(str) != dp.end()) return dp[str];

        int ans = 1e9;
        if(!isF) ans = f(i+1, 1, isS, word[i], lastS, word);
        else {

            ans = findDis(lastF, word[i]) + f(i+1, isF, isS, word[i], lastS, word);
            if(!isS) ans = min(ans, f(i+1, isF, 1, lastF, word[i], word));
            else ans = min(ans, findDis(lastS, word[i]) + f(i+1, isF, isS, lastF, word[i], word));
        
        }
        return dp[str] = ans;
    }

    int minimumDistance(string word) {
        
        return f(0, 0, 0, '-', '-', word);
    }
};