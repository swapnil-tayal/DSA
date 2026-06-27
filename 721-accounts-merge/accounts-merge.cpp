class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int i) {
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }

    void unite(int x, int y) {
        int s1 = find(x), s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) parent[s1] = s2;
            else if (rank[s1] > rank[s2]) parent[s2] = s1;
            else parent[s2] = s1, rank[s1]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        map<string, int> mailNode;
        int n = accounts.size();
        DSU *dj = new DSU(n);
        
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mailNode.count(mail) == 0){
                    mailNode[mail] = i;
                }else{
                    dj->unite(i, mailNode[mail]);
                }
            }
        }

        vector<vector<string>> node(n);
        for(int i=0; i<n; i++){
            node[i].push_back(accounts[i][0]);
        }
        set<string> st;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(st.count(accounts[i][j])) continue;
                node[dj->find(mailNode[accounts[i][j]])].push_back(accounts[i][j]);
                st.insert(accounts[i][j]);
            }
        }
        vector<vector<string>> res;
        for(auto &i: node){
            if(i.size() == 1) continue;
            sort(i.begin()+1, i.end());
            res.push_back(i);
        }
        return res;
    }
};