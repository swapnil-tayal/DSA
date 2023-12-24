/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIteratorAC {
    stack<TreeNode*> st;
public:
    BSTIteratorAC(TreeNode* root) {
        
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    TreeNode* next() {
        
        TreeNode* node = st.top();
        TreeNode* ans = st.top();
        // node = st.top();
        st.pop();
        if(node->right){
            node = node->right;
            st.push(node);
            node = node->left;
            while(node){
                st.push(node);
                node = node->left;
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
class BSTIteratorDC {
    stack<TreeNode*> st;
public:
    BSTIteratorDC(TreeNode* root) {
        
        while(root){
            st.push(root);
            root = root->right;
        }
    }
    
    TreeNode* prev() {
        
        TreeNode* node = st.top();
        TreeNode* ans = st.top();
        // node = st.top();
        st.pop();
        if(node->left){
            node = node->left;
            st.push(node);
            node = node->right;
            while(node){
                st.push(node);
                node = node->right;
            }
        }
        return ans;
    }
    
    bool hasPrev() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIteratorAC *s = new BSTIteratorAC(root);
        BSTIteratorDC *e = new BSTIteratorDC(root);
        
        TreeNode* val1 = s->next();
        TreeNode* val2 = e->prev();
        
        while(s->hasNext() and e->hasPrev()){
            
            if(val1 == val2) return false;
            
            if(val1->val + val2->val > k){
                val2 = e->prev();
            }else if(val1->val + val2->val < k){
                val1 = s->next();
            }else return true;
        }
        return false;
    }
};