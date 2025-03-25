class Solution {
public:

    int f(vector<pair<int,int>> a){

        vector<pair<int,int>> v;
        sort(a.begin(), a.end());
        int currMin = a[0].first;
        int currMax = a[0].second;
        // cout<<"--\n";
        // for(auto &i: a){
        //     cout<<i.first<<' '<<i.second<<'\n';
        // }
        // cout<<'\n';
        for(int i=1; i<a.size(); i++){
            if(a[i].first >= currMax){
                v.push_back({currMin, currMax});
                currMin = a[i].first;
            }
            currMax = max(currMax, a[i].second);
        }
        v.push_back({ currMin, currMax });
        // for(auto &i: v){
        //     cout<<i.first<<' '<<i.second<<'\n';
        // }
        // cout<<"--\n";
        return v.size() >= 3;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        
        vector<pair<int,int>> x, y;
        for(auto i: rectangles){
            x.push_back({ i[0], i[2] });
            y.push_back({ i[1], i[3] });
        }
        return f(x) || f(y);
    }
};