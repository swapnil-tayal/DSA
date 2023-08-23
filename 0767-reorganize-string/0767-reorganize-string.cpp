class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.size();
        map<char, int> mp;
        for(auto i: s) mp[i]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto i: mp) pq.push({ i.second, i.first });
              
        string str;
        
        while(pq.size() > 1){
            
            pair<int,char> p1 = pq.top();
            pq.pop();
            pair<int,char> p2 = pq.top();
            pq.pop();
            
            str += p1.second;
            str += p2.second;
            
            if(p1.first - 1 > 0) pq.push({ p1.first-1, p1.second });
            if(p2.first - 1 > 0) pq.push({ p2.first-1, p2.second });
            
        }
        if(pq.size()){
            int k = pq.top().first;
            while(k--)
            str += pq.top().second;
        }
        for(int i=1; i<n; i++){
            if(str[i] == str[i-1]) return "";
        }
        return str;
    }
};