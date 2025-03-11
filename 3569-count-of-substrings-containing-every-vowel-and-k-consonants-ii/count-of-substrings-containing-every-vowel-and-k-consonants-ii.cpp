class Solution {
public:

    int f(char ch){
        return (ch=='a') || (ch=='e') || (ch=='i') || (ch=='o') || (ch=='u');
    }

    long long countOfSubstrings(string s, int k) {
        
        map<char,int> mp;
        int cnt = 0;
        int n = s.size();
        int i = 0;
        int j = 0;
        long long ans = 0;

        vector<int> arr(n, 0);
        int check = n;
        for(int i=n-1; i>=0; i--){
            arr[i] = check;
            if(!f(s[i])) check = i;
        }

        while(j < n){

            if(f(s[j])) mp[s[j]]++;
            else cnt++;
            if(mp.size() < 5) j++;
            else if(cnt < k) j++;
            else{
                while(cnt > k){
                    if(f(s[i])) mp[s[i]]--;
                    else cnt--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                while(mp.size() == 5 and cnt == k){
                    ans += arr[j]-j;
                    if(f(s[i])) mp[s[i]]--;
                    else cnt--;
                    if(mp[s[i]] <= 0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};