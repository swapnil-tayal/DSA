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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* curr;
        ListNode* prev;
        prev = head;
        curr = head->next;
        int maxi = -1;
        int mini = 1e9;
        int ind = 1;
        int fir = -1;
        int lst = -1;

        while(curr){

            if(curr->next == NULL) break;
            int a1 = prev->val;
            int a2 = curr->val;
            int a3 = curr->next->val;
            if((a2 > a1 and a2 > a3) || (a2 < a1 and a2 < a3)){

                if(fir == -1) fir = ind;
                if(fir != ind){
                    maxi = ind - fir;
                    mini = min(mini, ind - lst);
                }
                lst = ind;
            }
            prev = curr;
            curr = curr->next;
            ind++;
        }
        if(maxi == -1) return {-1, -1};
        return {mini, maxi};
    }
};