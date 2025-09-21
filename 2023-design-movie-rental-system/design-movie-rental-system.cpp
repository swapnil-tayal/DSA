class MovieRentingSystem {
    map<int, set<pair<int,int>>> available;
    map<pair<int,int>, int> movie_price;
    set<vector<int>> rented;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &i: entries){
            available[i[1]].insert({i[2], i[0]});
            movie_price[{ i[1], i[0] }] = i[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> arr;
        for(auto &i: available[movie]){
            arr.push_back(i.second);
            if(arr.size() == 5) return arr;
        }
        return arr;
    }
    
    void rent(int shop, int movie) {
        int price = movie_price[{movie, shop}];
        rented.insert({price, shop, movie});
        available[movie].erase({price, shop});  
    }
    
    void drop(int shop, int movie) {
        int price = movie_price[{movie, shop}];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});  
    }
    
    vector<vector<int>> report() {        
        vector<vector<int>> ans;
        for (auto &i : rented) {
            ans.push_back({i[1], i[2]});
            if (ans.size() == 5) break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */