class node{
    public:
    int data;
    int i;
    int j;
    
    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};
class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        priority_queue<node*, vector<node*>, compare> mih;
        
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            mih.push(new node(nums[i][0], i, 0));
            maxi = max(maxi, nums[i][0]);
            mini = min(mini, nums[i][0]);
        }
        
        int a = maxi;
        int b = mini;
        int sum = maxi - mini;
        
        while(!mih.empty()){
            node* top = mih.top();
            mih.pop();
            mini = top->data;
            
            if(maxi - mini < sum){
                a = maxi;
                b = mini;
                sum = maxi - mini;
            } 
            
            int i = top->i;
            int j = top->j;
            if(j+1 < nums[i].size()){
                maxi = max(maxi, nums[i][j+1]);
                node* temp  = new node(nums[i][j+1], i, j+1);
                mih.push(temp);
            }else{
                break;
            }
            
        }
        
        vector<int> arr = {a, b};
        return arr;
        
    }
};