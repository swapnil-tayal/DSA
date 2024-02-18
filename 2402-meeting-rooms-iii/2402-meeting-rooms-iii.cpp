class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        int m = meetings.size();
        // if(m <= n) return 0; 
        
        vector<long long> room(n, 0);
        vector<long long> freq(n, 0);
        sort(meetings.begin(), meetings.end());
        
        for(int i=0; i<m; i++){
            
            long long roomNo = 1e9;
            
            long long currStart = meetings[i][0];
            
            for(int k=0; k<n; k++){
                if(room[k] <= currStart){
                    roomNo = k;
                    break;
                }
            }
            if(roomNo != 1e9){
                room[roomNo] = meetings[i][1];
                freq[roomNo]++;
            
            }
            else{
                
                long long minTime = LONG_MAX;
                for(int k=0; k<n; k++){
                    
                    if(room[k] < minTime){
                        minTime = room[k];
                        roomNo = k;
                    }
                }
                room[roomNo] += meetings[i][1] - meetings[i][0];
                freq[roomNo]++;
            }
        }
        // for(auto i: freq) cout<<i<<' ';
        long long maxFreq = *max_element(freq.begin(), freq.end());
        int ind = find(freq.begin(), freq.end(), maxFreq) - freq.begin();
        return ind;
    }
};