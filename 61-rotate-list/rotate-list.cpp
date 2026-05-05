
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head) return NULL;
        if(k == 0) return head;
        ListNode *temp = head;
        int n = 0;
        ListNode* last;
        while(temp != NULL){
            last = temp;
            temp = temp->next;
            n++;
        }
        k = k % n;
        if(k == 0) return head;

        int x = n-k;
        temp = head;
        ListNode* newHead = head;
        while(x--) {
            if(x == 0) newHead = temp->next;
            else temp = temp->next;
        }
        temp->next = NULL;
        last->next = head;
        return newHead;
    }
};