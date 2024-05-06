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
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* next;
        ListNode* curr = head;
        
        while(curr){
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        
        head = reverseList(head);
        int maxi = 0;
        
        ListNode* newList = new ListNode(head->val);
        ListNode* newListHead = newList;
        ListNode* temp = head;
        temp = temp->next;
        maxi = head->val;
        
        while(temp){
            
            if(temp->val >= maxi) {    
                newList->next = new ListNode(temp->val);
                newList = newList->next;
            }
            maxi = max(maxi, temp->val);
            temp = temp->next;
        }
        return reverseList(newListHead);
    }
};


