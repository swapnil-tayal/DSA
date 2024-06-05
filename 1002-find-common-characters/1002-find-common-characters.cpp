class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<string> arr;
        for(char ch='a'; ch<='z'; ch++){
            
            int cnt = 0;
            int maxi = 1e9;
            for(auto i: words){
                map<char,int> mp;
                for(auto j: i) mp[j]++;
                
                if(mp.find(ch) != mp.end()){
                    cnt++;
                    maxi = min(maxi, mp[ch]);
                }
            }
            if(cnt == words.size()){
                
                while(maxi--){
                    string str;
                    str += ch;
                    arr.push_back(str);
                }
            }
        }
        return arr;
    }
};