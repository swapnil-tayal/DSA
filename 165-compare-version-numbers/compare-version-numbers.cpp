class Solution{
    
vector<string> split(string str, char del){
    
    string temp = "";
    vector<string> a;
    for(int i=0; i<(int)str.size(); i++){
        if(str[i] != del){
            temp += str[i];
        }
        else{
            a.push_back(temp);
            temp = "";
        }
    }
    a.push_back(temp);
    return a;
}
    
public:
    int compareVersion(string version1, string version2) {
        
        vector<string> a1 = split(version1, '.');
        vector<string> a2 = split(version2, '.');
        
        vector<int> q1, q2;
        for(auto i: a1){
            int num = stoi(i);
            // if(num == 0) continue;
            q1.push_back(num);
        }
        for(auto i: a2){
            int num = stoi(i);
            // if(num == 0) continue;
            q2.push_back(num);
        }
        while(q1.size() and q1.back() == 0){
            q1.pop_back();
        }
        while(q2.size() and q2.back() == 0){
            q2.pop_back();
        }
        
        int n = min(q1.size(),q2.size());
        for(int i=0; i<n; i++){
            if(q1[i] < q2[i]) return -1;
            if(q1[i] > q2[i]) return 1;
        }
        if(q1.size() > q2.size()) return 1;
        if(q2.size() > q1.size()) return -1;
        return 0;
    }
};