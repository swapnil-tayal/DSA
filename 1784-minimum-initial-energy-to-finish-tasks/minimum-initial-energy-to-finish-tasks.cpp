class Solution {
public:

    int f(int mid, vector<vector<int>> &tasks){
        int n = tasks.size();
        for(int i=0; i<n; i++){
            if(tasks[i][1] <= mid){
                mid -= tasks[i][0];
            } else return 0;
        }
        return 1;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){
            // if(a[1] == b[1]) return a[0] < b[0];
            return (a[1]-a[0]) > (b[1]-b[0]);
        });
        // for(auto i: tasks){
        //     cout<<i[0]<<' '<<i[1]<<'\n';
        // }

        int l = 0;
        int h = 1e9;
        int ans = 0;
        // cout<<f(8, tasks)<<'\n';

        while(l <= h){

            int mid = (l+h)/2;
            if(f(mid, tasks)){

                ans = mid;
                h = mid-1;

            } else l = mid+1;
        }
        return ans;
        
    }
};