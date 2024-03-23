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
    void reorderList(ListNode* head) {
        
        if(!head)return;
        
        vector<int> arr;
        
        ListNode* temp = head;
        
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        
        temp = head;
        int i = 0;
        int count = 0;
        int n = arr.size();
        
        while(temp){
            
            if(count % 2 == 0){
                temp->val = arr[i];
            }else{
                temp->val = arr[n-i-1];
                i++;
            }
            count++;
            temp = temp->next;   
        }      
    }
};