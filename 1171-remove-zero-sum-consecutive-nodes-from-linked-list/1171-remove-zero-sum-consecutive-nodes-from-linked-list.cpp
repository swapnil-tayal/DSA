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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        vector<int> a;
        ListNode* temp = head;
        while(temp){
            a.push_back(temp->val);
            temp = temp->next;
        }
        int n = a.size();
        set<int> st;
        for(int i=0; i<n; i++) st.insert(i);
        
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += a[j];
                if(sum == 0){
                    for(int k=i; k<=j; k++) st.erase(k);
                    i = j;
                    break;
                }
            }
        }
        ListNode* ans = new ListNode(-1);
        temp = ans;
        for(int i=0; i<n; i++){
            if(st.count(i)){
                temp->next = new ListNode(a[i]);
                temp = temp->next;
            }
        }
        return ans->next;
    }
};