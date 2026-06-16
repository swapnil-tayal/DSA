class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> st;
        for(auto &i: wordList){
            st.insert(i);
        }
        int cnt = 1;
        while(!q.empty()){

            int n = q.size();
            while(n--){
                string str = q.front();
                if(str == endWord) return cnt;
                q.pop();
                for(int k=0; k<str.size(); k++){
                    string temp = str;
                    for(char ch='a'; ch<='z'; ch++){
                        temp[k] = ch;
                        if(st.count(temp)){
                            st.erase(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            cnt++;
        }
        return 0;
    }
};