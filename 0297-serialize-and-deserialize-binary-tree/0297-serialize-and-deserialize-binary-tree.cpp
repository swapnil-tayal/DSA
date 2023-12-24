/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> arr;
        
        while(!q.empty()){
            
            int n = q.size();
            
            while(n--){
                    
                TreeNode* node = q.front();
                if(node == NULL) arr.push_back(1001);
                else arr.push_back(node->val);
                q.pop();
                
                if(node == NULL) continue;
                else{
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        while(arr.size() and arr.back() == -1) arr.pop_back();
        string str;
        for(auto i: arr){
            str += to_string(i);
            str += ",";
        }
        // cout<<str<<' ';
        return str;
    }

    vector<int> strToArr(string &data){
        // cout<<data<<'\n';
        
        vector<int> arr;
        int n = data.size();
        int val = 0;
        int isNeg = 0;
        
        for(int i=0; i<n; i++){
            
            if(data[i] == ','){
                if(isNeg) val = -val;
                isNeg = 0;
                arr.push_back(val);
                val = 0;
            }
            else if(data[i] >= '0' and data[i] <= '9') val = val*10 + (data[i]-'0');
            else isNeg = 1;
        }
        // for(auto i: arr) cout<<i<<' ';
        return arr;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<int> arr = strToArr(data);
        
        queue<TreeNode*> q;
        int i = 0;
        int n = arr.size();
        TreeNode* root = new TreeNode(arr[0]);
        if(root->val == 1001) return NULL;
        q.push(root);
        i = 1;
        
        while(i < n){
            
            TreeNode* left = new TreeNode(arr[i++]);
            TreeNode* right = new TreeNode(1001);
            if(i < n){
                right = new TreeNode(arr[i++]);
            }
            TreeNode* top = q.front();
            q.pop();
            
            if(left->val != 1001){
                top->left = left;
                q.push(top->left);
            }
            if(right->val != 1001){
                top->right = right;
                q.push(top->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));