class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<vector<string>> arr;
        int n = words.size();
        vector<string> str;
        int len = 0;
        int i = 0;
        
        while(i < n){
            if(str.size() == 0){
                str.push_back(words[i]);
                len += words[i].size();
                i++;
            }
            else{
                if(len + str.size() + words[i].size() <= maxWidth){
                    str.push_back(words[i]);
                    len += words[i].size();
                    i++;
                }else{
                    arr.push_back(str);
                    str = vector<string>();
                    len = 0;
                }
            }
        }
        if(str.size()) arr.push_back(str);

        // for(auto i: arr){
        //     for(auto j: i){
        //         cout<<j<<' ';
        //     }
        //     cout<<'\n';
        // }
        
        vector<string> ans;
        for(int i=0; i<arr.size(); i++){
            
            int len = 0;
            for(auto &i: arr[i]) len += i.size();

            int spaceLeft = maxWidth - len;
            int equalSpace = arr[i].size() > 1 ? spaceLeft / (arr[i].size()-1) : 0;
            int leftOut = arr[i].size() > 1 ? spaceLeft % (arr[i].size()-1) : 0;

            if(i == arr.size()-1){
                equalSpace = 1;
                leftOut = 0;
            }

            string str = "";
            for(int j=0; j<arr[i].size()-1; j++){
                str += arr[i][j];
                for(int k=0; k<equalSpace; k++) str += " ";
                if(leftOut-- > 0) str += " ";
            }
            str += arr[i][arr[i].size()-1];
            while(str.size() < maxWidth) str += " ";
            ans.push_back(str);
        }
        return ans;
    }
};