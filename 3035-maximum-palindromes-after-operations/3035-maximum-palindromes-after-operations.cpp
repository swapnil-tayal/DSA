bool cmp(string &s1, string &s2){
    return s1.size() < s2.size();
}

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        
        int n = words.size();
        int even = 0;
        int odd = 0;
        map<int,int> mp;
        for(auto i: words){
            for(auto j: i){
                mp[j]++;
            }
        }
        for(auto i: mp){
            if(i.second%2 == 0) even += i.second;
            else{
                even += i.second-1;
                odd++;
            }
        }
        
        int cnt = 0;
        sort(words.begin(), words.end(), cmp);
        
        for(int i=0; i<words.size(); i++){
            
            int k = words[i].size();
            int reqEven = 0;
            int reqOdd = 0;
            if(k%2 == 0){
                
                reqEven = k;
                // cout<<words[i]<<' '<<even<<'\n';
                if(reqEven <= even){
                    even -= reqEven;
                    reqEven = 0;
                    cnt++;
                }
            
            }else{
                
                reqEven = k-1;
                reqOdd = 1;
                if(reqEven <= even){
                    even -= reqEven;
                    reqEven = 0;
                    
                    if(odd >= 1){
                        odd -= 1;
                        cnt++;
                    }else if(even >= 2){
                        even -= 2;
                        odd++;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};