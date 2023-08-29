//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends

void reverseLL(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* nxt;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}


class Solution
{
    public:
    Node *compute(Node *head)
    {
        reverseLL(head);
        int max = -1;
        Node* ans = new Node(-1);
        Node* anstemp = ans;
        Node* temp = head;
        while(temp != NULL){
            if (temp->data >= max){
                max = temp->data;
                Node* n = new Node(temp->data);
                anstemp->next = n;
                anstemp = anstemp->next;
            }temp = temp->next;
        }
        ans = ans->next;
        reverseLL(ans);
        return ans;
    }
    
};
   



//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends