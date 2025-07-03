class Solution {
public:

    string f(string str){
        string temp;
        for(auto i: str){
            char ch = char((((i-'a')+1)%26) + 'a');
            temp += ch;
        }
        return temp;
    }

    char kthCharacter(int k) {
        
        string str = "a";
        while(str.size() < k){
            str += f(str);
        }
        return str[k-1];
    }
};