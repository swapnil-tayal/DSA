class Solution {
    vector<string> arr;
public:

    void f(int n, char ch, string str){
        if(n == 0){
            arr.push_back(str);
            return;
        }
        if(ch == '-'){
            f(n-1, 'a', str + 'a');
            f(n-1, 'b', str + 'b');
            f(n-1, 'c', str + 'c');
        
        }else{
            if(ch == 'a'){
                f(n-1, 'b', str + 'b');
                f(n-1, 'c', str + 'c');
            }else if(ch == 'b'){
                f(n-1, 'a', str + 'a');
                f(n-1, 'c', str + 'c');
            }else{
                f(n-1, 'a', str + 'a');
                f(n-1, 'b', str + 'b');
            }
        }
    }

    string getHappyString(int n, int k) {

        for(int i=n; i<=n; i++){
            f(n, '-', "");
        }
        sort(arr.begin(), arr.end());
        
        // for(auto i: arr) cout<<i<<' ';
        // cout<<'\n';

        if(arr.size() < k) return "";
        return arr[k-1];
    }
};
