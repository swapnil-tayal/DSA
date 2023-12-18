//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* merge(Node* h1, Node* h2){
    
    Node* th1 = h1;
    Node* th2 = h2;
    Node* res = new Node(-1);
    Node* ret = res;
    
    while(th1 and th2){
        
        if(th1->data < th2->data){
            res->bottom = new Node(th1->data);
            th1 = th1->bottom;
            
        }else if(th2->data <= th1->data){
            res->bottom = new Node(th2->data);
            th2 = th2->bottom;
            
        }res = res->bottom;
    }
    while(th1){
        res->bottom = new Node(th1->data);
        th1 = th1->bottom;
        res = res->bottom;
    }
    while(th2){
        res->bottom = new Node(th2->data);
        th2 = th2->bottom;
        res = res->bottom;
    }
    return ret->bottom;
}
    
Node *flatten(Node *root){
   // Your code here
    if(!root->next) return root;
    Node* head = root;
    Node* temp = head->next;
   
    while(temp){
        head = merge(head, temp);
        temp = temp->next;
    }
    return head;
}

