class Solution {
public:

    bool f(char ch){
        return ch=='a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n = words.size();
        vector<int> a;

        for(auto &i: words){
            if(f(i.front()) and f(i.back())){
                if(a.size()) a.push_back(a.back() + 1);
                else a.push_back(1);
            }else{
                if(a.size()) a.push_back(a.back() + 0);
                else a.push_back(0);    
            }
        }
        vector<int> ans;
        for(auto &i: queries){
            int sum = a[i[1]];
            if(i[0]-1 >= 0) sum -= a[i[0]-1];
            ans.push_back(sum); 
        }
        return ans;
    }
};