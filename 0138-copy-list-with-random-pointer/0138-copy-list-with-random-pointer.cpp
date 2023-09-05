/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head) return NULL;
        
        Node* newNode = new Node(head->val);
        Node* temp = newNode;
        Node* tempHead = head;
        int cnt = 0;
        
        while(tempHead){
            
            Node* x = new Node(tempHead->val);
            temp->next = x;
            temp = temp->next;
            tempHead = tempHead->next;
            cnt++;
        }
        
        vector<int> inD(cnt, 0);
        
        tempHead = head;
        int ind = 0;
        
        while(tempHead){
            
            Node* rand = NULL;
            if(tempHead->random){
                
                rand = tempHead->random;
                int x = 0;
                while(rand){
                    rand = rand->next;
                    x++;
                }
                inD[ind++] = cnt-x;
            
            }else inD[ind++] = -1;
            tempHead = tempHead->next;
        }
        
        // for(auto i: inD) cout<<i<<' ';
        // cout<<'\n';
        
        temp = newNode->next;
        ind = 0;
        while(temp){
            
            int k = inD[ind++];
            if(k == -1) temp->random = NULL;
            else{
                
                Node* tempRand = newNode->next;
                int x = k - 1;
                // cout<<x<<' ';
                while(x >= 0){
                    // if(!tempRand) break;
                    tempRand = tempRand->next;
                    x--;
                }
                temp->random = tempRand;
            }
            temp = temp->next;
        }
        
        return newNode->next;
    }
};