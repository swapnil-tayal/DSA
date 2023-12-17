class Solution {
    int ans;
public:
    
    void merge(vector<int> &arr, long long s1, long long m, long long e2){
        
        vector<long long> temp;
        long long i = s1;
        long long j = m+1;
        
        vector<int> a;
        for(int i=s1; i<=m; i++) a.push_back(arr[i]);
        
        for(int i=m+1; i<=e2; i++){
            
            int ind = lower_bound(a.begin(), a.end(), (long long)(2*(long long)arr[i])+ 1) - a.begin();
            if(ind == arr.size()) continue;
            ans += a.size() - ind;
        }
        
        while(i <= m and j <= e2){
            if(arr[i] < arr[j]) temp.push_back(arr[i++]);
            else{
                if(arr[i] > 2*(long long)arr[j]){
                    // cout<<i<<' '<<j<<'\n';
                    // ans += (m-i+1);
                }
                temp.push_back(arr[j++]);
            }
        }
        while(i <= m) temp.push_back(arr[i++]);
        while(j <= e2) temp.push_back(arr[j++]);
        
        int k = 0;
        for(int i=s1; i<=e2; i++){
            arr[i] = temp[k++];
        }
    }
    
    void mergeSort(vector<int> &arr, long long s, long long e){
        
        if(s >= e) return;
        long long mid = (s+e)/2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        merge(arr, s, mid, e);
    }
    
    int reversePairs(vector<int>& nums) {
        ans = 0;
        mergeSort(nums, 0, nums.size()-1);
        return ans;
    }
};