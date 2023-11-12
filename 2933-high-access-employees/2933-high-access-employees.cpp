class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        
        vector<string> ans;
        map<string, vector<int>> mp;
        
        for(auto i: at){
            
            int min = (i[1][2] - '0');
            min *= 10;
            min += (i[1][3] - '0');
            
            int hr = (i[1][0] - '0');
            hr *= 10;
            hr += (i[1][1] - '0');
            
            
            int time = hr*60 + min;
            mp[i[0]].push_back(time);
        }
        
        for(auto i: mp){
            
            sort(i.second.begin(), i.second.end());
            int cnt = 0;
            vector<int> temp = i.second;
            int j = 1;
            for(int j=1; j<temp.size()-1; j++){
                
                if(temp[j+1] - temp[j-1] < 60){
                    ans.push_back(i.first);
                    break;
                }
            }
        }
        
        return ans;
    }
};