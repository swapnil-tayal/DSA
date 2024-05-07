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
    
    ListNode* doubleIt(ListNode* head) {
        
        head = reverseList(head);
        int carry = (head->val*2) / 10;
        
        ListNode* ans = new ListNode((head->val*2) % 10);
        ListNode* temp = ans;
        head = head->next;
        
        while(head){
            
            int sum = (2*(head->val) + carry);
            temp->next = new ListNode(sum % 10);
            carry = sum/10;
            temp = temp->next;
            head = head->next;
        }
        if(carry != 0) temp->next = new ListNode(carry);
        return reverseList(ans);
    }
};







