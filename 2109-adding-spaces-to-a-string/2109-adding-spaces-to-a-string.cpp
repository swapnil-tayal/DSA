class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int len = s.size() + spaces.size();  
        string res(len, ' ');                    
        int skip = 0, it = 0;                

        for (int i = 0; i < s.size(); i++) {
            if (it < spaces.size() && i == spaces[it]) { 
                it++;
                skip++;
            }
            res[i + skip] = s[i];   
        }
        return res;
    }
};