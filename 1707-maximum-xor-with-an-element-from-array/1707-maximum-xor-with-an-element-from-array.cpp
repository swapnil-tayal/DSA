class Node{
    Node* link[2];
    public:
    void put(int x, Node* node){
        link[x] = node;
    }
    Node* get(int x){
        return link[x];
    }
    bool containsKey(int x){
        if(link[x] == NULL) return false;
        return true;
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int n){
        
        Node* node = root;
        bitset<32> it(n);
        for(int i=31; i>=0; i--){
            if(!node->containsKey(it[i])){
                node->put(it[i], new Node());
            }
            node = node->get(it[i]);
        }
    }
    int getMax(int x){
        
        Node* node = root;
        bitset<32> it(x);
        int ans = 0; 
        
        for(int i=31; i>=0; i--){
            int y = 1 - it[i];
            if(node->containsKey(y)){
                ans = ans | (1 << i);
                node = node->get(y);
            
            }else node = node->get(it[i]);
        }
        return ans;
    }
};

bool cmp(vector<int> &q1, vector<int> &q2){
    return q1[1] < q2[1];
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        int q = queries.size();
        for(int i=0; i<q; i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), cmp);
        
        // for(auto i: queries){
        //     for(auto j: i) cout<<j<<' ';
        //     cout<<'\n';
        // }
        
        sort(nums.begin(), nums.end());
        vector<int> ans(q);
        Trie *trie = new Trie(); 
        vector<int> temp;
        
        int pre = 0;
        for(int i=0; i<q; i++){
            
            int ind = upper_bound(nums.begin(), nums.end(), queries[i][1]) - nums.begin();
            // cout<<ind<<' ';
            if(ind == 0) ans[queries[i][2]] = -1;
            else{
                
                for(int k=pre; k<ind; k++){
                    trie->insert(nums[k]);
                    temp.push_back(nums[k]);
                }
                pre = ind;
                ans[queries[i][2]] = trie->getMax(queries[i][0]);
            }
            // for(auto k: temp) cout<<k<<' ';
            // cout<<'\n';
        }
        return ans;
    }
};