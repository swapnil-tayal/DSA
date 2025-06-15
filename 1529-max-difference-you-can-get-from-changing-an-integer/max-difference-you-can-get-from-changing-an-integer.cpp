class Solution {
public:

    int f(string str, char from, int to){
        int orignalSize = str.size();
        for(auto &i: str){
            if(i == from) i = to;
        }
        if(orignalSize == to_string(stoi(str)).size() and str != "0"){
            return stoi(str);
        }
        else return -1;
    }

    int maxDiff(int num) {
        
        string str = to_string(num);
        int n = str.size();

        set<int> st;
        for(char i='0'; i<='9'; i++){
            for(int j='0'; j<='9'; j++){
                int val = f(str, i, j);
                if(val != -1) st.insert(val);
            }
        }
        int ans = -1e9;
        vector<int> nums(st.begin(), st.end());
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                ans = max(ans, abs(nums[i]-nums[j]));
            }
        }
        return ans;
    }
};