class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> arr;
        int n = s.size();
        string temp = "";
        
        for(int i=0; i<n; i++){
            if(i == n-1 and s[i] != ' '){
                temp += s[i];
                arr.push_back(temp);
                break;
            }
            if(s[i] == ' ' and temp != ""){
                arr.push_back(temp);
                temp = "";
                continue;
            }
            if(s[i] != ' ')temp = temp + s[i];
            
        }
        n = arr.size();
        for(int i=0; i<n; i++){
            reverse(arr[i].begin(), arr[i].end());
        }
        s = "";
        n = arr.size();
        for(int i=0; i<n; i++){
            s += arr[i];
            s += " ";
        }
        s.pop_back();
        return s;
        
    }
};