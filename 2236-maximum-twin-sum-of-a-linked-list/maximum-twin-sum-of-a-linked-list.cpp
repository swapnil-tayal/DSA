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
    int pairSum(ListNode* head) {
        
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            n++;
        }
        int sum = 0;
        ListNode* head2 = head;
        int k = n/2;
        while(k--) head2 = head2->next;
        
        ListNode* curr = head2;
        ListNode* prev = NULL;
        ListNode* nxt;
        k = n/2;

        while(k--){

            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        k = n/2;
        while(k--){
            sum = max(sum, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }
        return sum;
    }
};