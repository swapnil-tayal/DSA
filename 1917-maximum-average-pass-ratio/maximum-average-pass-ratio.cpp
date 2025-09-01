class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<pair<double,int>> pq;
        for(int i=0; i<classes.size(); i++){

            double p = classes[i][0];
            double t = classes[i][1];
            double pNew = classes[i][0] + 1;
            double tNew = classes[i][1] + 1;
            double change = (pNew/tNew) - (p/t);
            pq.push({change, i});

        }

        while(extraStudents--){

            double change = pq.top().first;
            int ind = pq.top().second;
            classes[ind][0]++;
            classes[ind][1]++;
            pq.pop();
            double newChange = (double(classes[ind][0]+1) / double(classes[ind][1]+1)) - ((double)classes[ind][0] / (double)classes[ind][1]);
            pq.push({newChange, ind});

        }

        double ans = 0;
        for(auto i: classes){
            ans += ((double)i[0] / (double)i[1]);
        }
        ans = ans / classes.size();
        return ans;
    }
};