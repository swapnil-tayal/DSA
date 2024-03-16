struct PairComparator {
    bool operator()(const pair<int, char>& p1, const pair<int, char>& p2) const{
        if (p1.first != p2.first)
            return p1.first > p2.first;
        return p1.second > p2.second;
    }
};

class Solution {
public:
    string minimizeStringValue(string s) {
        
        int n = s.size();
        priority_queue<pair<int,char>, vector<pair<int,char>>, PairComparator> pq;
        
        vector<int> a(26, 0);
        for(auto i: s){
            if(i == '?') continue;
            a[i-'a']++;
        }
        for(int i=0; i<26; i++){
            pq.push({ a[i], char(i+'a') });
        }
        
        string str = "";
        
        for(auto &i: s){
            
            if(i != '?') continue;
            int val = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            str += ch;
            pq.push({ val+1, ch });
        }
        sort(str.begin(), str.end());
        int ind = 0;
        for(auto &i: s){
            if(i == '?'){
                i = str[ind++];
            }
        }
        
        return s;
    }
};