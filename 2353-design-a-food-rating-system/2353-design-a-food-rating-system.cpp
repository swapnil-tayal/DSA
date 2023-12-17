class Compare {
    public:
       bool operator()(pair<int,string> a, pair<int,string> b){
           if(a.first == b.first){
               return a.second > b.second;
           }
           return a.first < b.first;
      }
};

class FoodRatings{
    
    map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, Compare>> mp;
    map<string, set<int>> remMp;
    map<string, int> currRating;
    map<string, string> foodCus;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int n = foods.size();
        for(int i=0; i<n; i++){
            mp[cuisines[i]].push({ ratings[i], foods[i] });
            currRating[foods[i]] = ratings[i];
            foodCus[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        
        remMp[food].erase(newRating);
        remMp[food].insert(currRating[food]);
        currRating[food] = newRating;
        
        mp[foodCus[food]].push({ newRating, food });
        
    }
    
    string highestRated(string cuisine) {
        
        // priority_queue<pair<int,string>, vector<pair<int,string>>, Compare> pq = mp[cuisine];
        
        // if(cuisine == "japanese") cout<<pq.top().first<<'\n';
        
        while(!mp[cuisine].empty() and remMp[mp[cuisine].top().second].count(mp[cuisine].top().first)){
            mp[cuisine].pop();
        }
        return mp[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */