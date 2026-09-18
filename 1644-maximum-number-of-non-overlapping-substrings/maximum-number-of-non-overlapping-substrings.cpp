class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        
        vector<int> count(26, 0);
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        vector<int> order;
        int n = s.size();

        for(int i=0; i<n; i++){
            
            int ind = s[i]-'a';
            if(count[ind] == 0){
                first[ind] = i;
                order.push_back(ind);
            }
            count[ind]++;
            last[ind] = i;
        }
        deque<vector<int>> q;
        vector<string> ans;
 
        for(auto &k: order){

            q.push_front({ first[k], last[k], count[k] });
            int left = 1e9;
            int right = -1e9;
            int total = 0;

            for(auto &i: q){

                total += i[2];
                left = min(left, i[0]);
                right = max(right, i[1]);

                if(total == right - left + 1){
                    ans.push_back({ s.substr(left, right-left+1) });
                    q.clear();
                    break;
                }
            }
        }
        return ans;
    }
};