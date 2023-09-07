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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* temp = new ListNode(-1);
        ListNode* newHead = temp;
        temp->next = head;
        
        for(int i=1; i<left; i++){
            temp = temp->next;
        }
        
        ListNode* temp2 = temp;
        ListNode* curr = temp->next;
        ListNode* nxt;
        ListNode* prev = NULL;
        
        for(int i=0; i<right-left+1; i++){
            
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        temp = prev;
        while(temp->next) temp = temp->next;
        temp->next = nxt;
        temp2->next = prev;
        
        return newHead->next;
    }
};