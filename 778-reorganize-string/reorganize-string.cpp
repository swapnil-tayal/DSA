class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char,int> mp;
        for(auto &i: s){
            mp[i]++;
        }
        int n = s.size();
        priority_queue<pair<int,int>> pq;
        for(auto i: mp){
            pq.push({ i.second, i.first });
        }
        s = string(n, '-');
        int ind = 0;
        int isDone = 0;

        while(!pq.empty()){

            char ch = pq.top().second;
            int cnt = pq.top().first;
            pq.pop();

            while(cnt--){
                s[ind] = ch;
                ind = (ind + 1) % n;
                if(ind > 0 and s[ind-1] == ch){
                    ind = (ind+1) % n;
                }
                while((cnt || pq.size()) && ind < n and s[ind] != '-'){
                    ind = (ind+1) % n;
                }
            }
        }
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]) return "";
        }
        return s;
    }
};