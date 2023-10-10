//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

    Node* createMap(Node* root, map<Node*, Node*> &nodeToParent, int t){
        Node* res = NULL;
        nodeToParent[root] = NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(t == front->data){
                res = front;
            }
            if(front->left){
                nodeToParent[front->left] = front; 
                q.push(front->left);
            }if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    
    vector<int> solveF(Node* root, map<Node*, Node*> nodeToParent, int k){
        queue<Node*> q;
        q.push(root);
        
        map<Node*, bool> visted;
        visted[root] = true;
        
        while(!q.empty()){
            int n = q.size();
            if(k == 0) break;
            
            for(int i=0; i<n; i++){
                Node* temp = q.front();
                q.pop();

                if(temp->left && !visted[temp->left]){
                    q.push(temp->left);
                    visted[temp->left] = true;
                    
                }if(temp->right && !visted[temp->right]){
                    q.push(temp->right);
                    visted[temp->right] = true;
                }
                if(nodeToParent[temp] && !visted[nodeToParent[temp]]){
                    visted[nodeToParent[temp]] = true;
                    q.push(nodeToParent[temp]);
                }
            }k--;
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->data);
            q.pop();
        }
        return res;
    }
    
public:

    vector <int> KDistanceNodes(Node* root, int t , int k)
    {
        // return the sorted vector of all nodes at k dist
        map<Node*, Node*> nodeToParent;
        Node* target = createMap(root, nodeToParent, t);
        
        vector<int> ans = solveF(target, nodeToParent, k);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends