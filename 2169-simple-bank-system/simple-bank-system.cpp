class Bank {
    int n;
    unordered_map<int, long long> mp;
public:
    Bank(vector<long long>& balance) {
        n = balance.size();
        for(int i=0; i<n; i++){
            mp[i+1] = balance[i];
        }
    }
    
    bool transfer(int a1, int a2, long long money) {
        if(a1 > n || a2 > n) return false;
        if(mp[a1] < money) return false;
        mp[a2] += money;
        mp[a1] -= money;
        return true;

    }
    
    bool deposit(int account, long long money) {
        if(account > n) return false;
        mp[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > n) return false;
        if(mp[account] < money) return false;
        mp[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */