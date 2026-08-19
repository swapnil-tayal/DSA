class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        
        int ans = 0;

        unordered_set<int> st;
        set<vector<int>> st2;
        for(auto &i: a){
            st.insert(i[0]);
            st2.insert(i);
        }
        ans += (n - st.size()) * 2;

        for(auto &i: st){

            if(!st2.count({ i, 2 }) and !st2.count({ i, 3 }) and !st2.count({ i, 4 }) and !st2.count({ i, 5 })){
                ans++;
                if(!st2.count({ i, 6 }) and !st2.count({ i, 7 }) and !st2.count({ i, 8 }) and !st2.count({ i, 9 })){
                    ans++;
                }
            }
            else if(!st2.count({ i, 4 }) and !st2.count({ i, 5 }) and !st2.count({ i, 6 }) and !st2.count({ i, 7 })){
                ans++;
            }
            else if(!st2.count({ i, 6 }) and !st2.count({ i, 7 }) and !st2.count({ i, 8 }) and !st2.count({ i, 9 })){
                ans++;
            }
        }
        return ans;
    }
};