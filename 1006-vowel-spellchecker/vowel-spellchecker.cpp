class Solution {
public:

    bool isVov(char &ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        set<string> orignalWords;
        map<string, string> lowerCase;
        map<string, string> vovelsCase;

        for(auto &i: wordlist){
            orignalWords.insert(i);
            string lowerI = i;
            transform(lowerI.begin(), lowerI.end(), lowerI.begin(), ::tolower);
            if(lowerCase.count(lowerI) == 0) lowerCase[lowerI] = i;

            string temp = "";
            for(auto &k: lowerI){
                if(!isVov(k)) temp += k;
                else temp += '-';
            }
            if(vovelsCase.count(temp) == 0) vovelsCase[temp] = i;
        }
        
        vector<string> ans;
        for(auto &i: queries){
            if(orignalWords.count(i)){
                ans.push_back(i);
                continue;
            }
            transform(i.begin(), i.end(), i.begin(), ::tolower);
            if(lowerCase.count(i)){
                ans.push_back(lowerCase[i]);
                continue;
            }
            string temp = "";
            for(auto &k: i){
                if(!isVov(k)){
                    temp += k;
                }else temp += '-';
            }
            if(vovelsCase.count(temp)) ans.push_back(vovelsCase[temp]);
            else ans.push_back("");
        }
        return ans;
    }
};