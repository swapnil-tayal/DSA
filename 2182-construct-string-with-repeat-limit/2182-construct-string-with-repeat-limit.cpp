class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        map<int,int> mp;
        for(auto i: s) mp[i]++;
        
        priority_queue<pair<char,int>> pq;
        for(auto i: mp) pq.push(i);
        
        string ans = "";
        
        while(!pq.empty()){
            
            char ch = pq.top().first;
            int sec = pq.top().second;
            pq.pop();
            
            if(ch == 'v') cout<<sec<<' ';
            
            for(int i=1; i<=sec; i++){
                ans += ch;
                if(i%repeatLimit == 0 and i != sec){
                    if(pq.size() == 0) break; 
                    char ch2 = pq.top().first;
                    int sec = pq.top().second;
                    pq.pop();
                    ans += ch2;
                    if(sec-1 > 0) pq.push({ ch2, sec-1 });
                }
            }
        }
        return ans;
    }
};
// "yxxvvvuusrrqqppopponliihgfeeddcbba"
// "yxxvvuvusrrqqppopponliihgfeeddcbba"