#include <iostream>
#include <bits/stdc++.h>
// #include "utilities.cpp"
using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, x, n) for (int i = x; i < n; i++)
#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>
#define ss second
#define ff first
const int mod = 1e9 + 7;

class Solution {
public:
    
    long long f(int i, int k, int maxSum, vector<int> &a, map<vector<int>, int> &dp){
        
        if(k < 0) return 0;
        if(maxSum < 0) return 0;
        if(i == a.size()){
            return (k==0 and maxSum==0);
        }
        if(dp.find({i, k, maxSum}) != dp.end()) return dp[{i, k, maxSum}];
        
        long long npick = f(i+1, k, maxSum, a, dp);
        long long x = a[i] % mod;
        long long y = f(i+1, k-1, maxSum - a[i], a, dp) % mod;
        long long pick = ((x) * (y)) % mod;
        return dp[{i, k, maxSum}] = (pick + npick) % mod;
    }
    
    int countKSubsequencesWithMaxBeauty(string s, int k){
        
        vector<int> mp(26, 0);
        for(auto i: s) mp[i-'a']++;
        
        vector<int> newArr;
        for(auto i: mp){
            if(i != 0) newArr.push_back(i);
        }
        sort(rall(newArr));
        
        if(newArr.size() < k) return 0;
        int maxSum = 0;
        for(int i=0; i<k; i++){
            maxSum += newArr[i];
        }
        // cout<<maxSum<<'\n';
        
        // for(auto i: newArr) cout<<i<<' ';
        
        map<vector<int>, int> dp;
        return f(0, k, maxSum, newArr, dp);
    }
};








