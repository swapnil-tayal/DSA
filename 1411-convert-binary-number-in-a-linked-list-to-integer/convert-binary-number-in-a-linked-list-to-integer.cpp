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
    int getDecimalValue(ListNode* head) {
        
        string str = "";
        while(head != NULL){
            str += to_string(head->val);
            head = head->next;
        }
        int ans = 0;
        cout<<str<<'\n';
        reverse(str.begin(), str.end());
        int x = 0;
        for(auto i: str){
            if(i == '1') ans += pow(2, x);
            x++; 
        }
        return ans;
    }
};