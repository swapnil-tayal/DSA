class Solution {
public:

    double f(vector<vector<int>> &a, double y){

        double area = 0;
        for(auto &i: a){
            double len = i[2];
            double tY = i[1] + len;
            if(y >= tY) continue;
            double remainingHeight = min(len, tY - y);
            area += len * remainingHeight;
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        
        double totalArea = f(squares, -1e9) / 2.0;
        cout<<totalArea;
        double s = 1e9;
        double e = -1e9;        
        for (auto& i : squares) {
            double L = i[2];
            double y0 = i[1];
            s = min(s, y0);
            e = max(e, y0+L);
        }
        double epsilon = 1e-5;

        while(e - s > epsilon){
            double mid = (s+e)/2;
            double area = f(squares, mid); 
            if(area > totalArea){
                s = mid;

            }else e = mid;
        }
        return s;
    }
};