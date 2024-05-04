class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n = people.size();
        int cnt = 0;
        sort(people.begin(), people.end());
        
        int i = 0;
        int j = n-1;
        while(j>=0 and people[j] >= limit){
            j--;
            cnt++;
        }
        
        if(i == j) return cnt+1;
        
        while(i <= j){
            // if(i == j) cnt++;
            if(people[i] + people[j] <= limit){
                i++;
            }
            cnt++;
            j--;
        }
        return cnt;
    }
};