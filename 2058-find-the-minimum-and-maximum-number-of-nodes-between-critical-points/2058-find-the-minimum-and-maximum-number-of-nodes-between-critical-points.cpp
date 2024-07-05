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
        
        if(!head || !head->next || !head->next->next){
            return {-1, -1};
        }
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = head->next->next;
        
        vector<int> arr;
        int i = 2;
        int mini = INT_MAX;
        int prv = i;
        
        while(nxt){
            if(prev->val < curr->val && nxt->val < curr->val){
                arr.push_back(i);
                if(i != prv){
                    mini = min(mini, i-prv);
                    prv = i;
                }
            }
            else if(prev->val > curr->val && nxt->val > curr->val){
                arr.push_back(i);
                if(i != prv){
                    mini = min(mini, i-prv);
                    prv = i;
                }
            }i++; 
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        
        if(arr.size() < 2){
            return {-1, -1};
        }
        if(arr.size() == 2){
            return {abs(arr[0]-arr[1]), abs(arr[0]-arr[1])};
        }
        
        int maxi = -1;
        maxi = arr[arr.size()-1] - arr[0];
        if(mini == INT_MAX){
            mini = -1;
        }
        return {mini, maxi};
    }
};