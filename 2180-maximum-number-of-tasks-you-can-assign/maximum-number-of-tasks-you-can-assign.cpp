class Solution {
public:

    int f(int cnt, vector<int> &t, vector<int> &w, int p, int s){

        multiset<int> ms;
        for(int i=0; i<w.size(); i++){
            ms.insert(w[i]);
        }
        for(int i=cnt-1; i>=0; i--){

            int task = t[i];
            auto it = ms.lower_bound(task);
            if(it != ms.end()) ms.erase(it);
            else{
                it = ms.lower_bound(task-s);
                if(p > 0 && it != ms.end()){
                    ms.erase(it);
                    p--;
                }else return 0;
            }
        }
        return 1;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int ans = 0;
        int s = 0;
        int e = min(workers.size(), tasks.size());

        while(s <= e){

            int mid = (s+e)/2;
            if(f(mid, tasks, workers, pills, strength)){
                ans = mid;
                s = mid+1;

            }else e = mid-1;
        }
        return ans;
    }
};