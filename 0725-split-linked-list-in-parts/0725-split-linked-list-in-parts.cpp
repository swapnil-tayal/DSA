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
    
    int len(ListNode* head){
        
        ListNode* tempHead = head;
        int cnt = 0;
        while(tempHead){
            cnt++;
            tempHead = tempHead->next;
        }
        return cnt;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> ans;
        int n = len(head);
        
        if(k > n){
            
            while(head){
                ans.push_back(new ListNode(head->val));
                head = head->next;
                k--;
            }
            while(k){
                ans.push_back(NULL);
                k--;
            }
            return ans;
        }
        
        int d = (n)/k;
        
        int extra = n%k;
        // cout<<d<<' '<<extra<<'\n';
        
        // cout<<head->next->val<<'\n';
        int x = d;
        // cout<<x<<'\n';
        ListNode* insertHead = new ListNode(head->val);
        ListNode* tempInsert = insertHead;
        head = head->next;
        
        while(head){
            
            // cout<<x<<' '<<extra<<'\n';
           if(d == 1 and extra > 0){
                tempInsert->next = new ListNode(head->val);
                tempInsert = tempInsert->next;
                extra--;
                head = head->next;
            }
            if(x == 1){
                
                ans.push_back(insertHead);
                // cout<<head->val<<' ';
                insertHead = new ListNode(head->val);
                tempInsert = insertHead;
                x = d;
                head = head->next;
                
            }else{
                tempInsert->next = new ListNode(head->val);
                tempInsert = tempInsert->next;
                x--;
                if(x == 1 and extra > 0){
                    head = head->next;
                    tempInsert->next = new ListNode(head->val);
                    tempInsert = tempInsert->next;
                    extra--;
                }
                head = head->next;
            }
        }
        // if(insertHead->val == -1) insertHead = insertHead->next;
        ans.push_back(insertHead);
        
        return ans;
        
    }
};