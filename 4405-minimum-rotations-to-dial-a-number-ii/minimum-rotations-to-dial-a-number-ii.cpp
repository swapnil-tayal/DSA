class Solution {
    vector<vector<int>> a;
public:

    void f(string s, int x){

        int n = s.size();
        int score = 0;
        vector<int> temp;
        for(auto &i: s){

            int num = i-'0';
            score += min(abs(num-x), 10-abs(num-x));
            x = num;
            temp.push_back(score);
        }
        reverse(temp.begin(), temp.end());
        a.push_back(temp);
    }

    int minRotations(int n, string s) {
        
        string rev = s;
        reverse(rev.begin(), rev.end());

        for(int i=0; i<=9; i++){
            f(rev, i);
        }

        int x = 0;
        int score = 0;
        int ans = 1e9;
        for(int i=0; i<n; i++){
            
            int num = s[i]-'0';
            ans = min(ans, score + a[x][i]);
            score += min(abs(num-x), 10-abs(num-x));
            x = num;
        }
        return ans;
    }
};