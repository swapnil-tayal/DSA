/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
class Solution {
public:
    
    bool check(ListNode* head, TreeNode* root){
        
        if(!head) return true;
        if(!root) return false;
        
        if(head->val != root->val) return false;
        bool l = check(head->next, root->left);
        bool r = check(head->next, root->right);
        return l||r;

    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        
        bool a = check(head, root);
        bool l = isSubPath(head, root->left);
        bool r = isSubPath(head, root->right);
        return a||l||r;
    }
};