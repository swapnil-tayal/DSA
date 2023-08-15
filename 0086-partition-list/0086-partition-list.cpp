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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* node1 = new ListNode(-1);
        ListNode* node2 = new ListNode(-1);
        ListNode* startNode2 = node2;
        ListNode* ans = node1;
        
        while(head){
            
            if(head->val < x){
                node1->next = new ListNode(head->val);
                node1 = node1->next;
                
            }else{
                node2->next = new ListNode(head->val);
                node2 = node2->next;
                
            }head = head->next;
        }
        node1->next = startNode2->next;
        return ans->next;
    }
};