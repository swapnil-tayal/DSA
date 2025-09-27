class Solution {
public:

    double findDis(vector<int> p1, vector<int> p2){
        double x = pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2);
        double dis = sqrt(x);
        return dis;
    }
    double findArea(double a, double b, double c){
        double s = (a+b+c)/2.0;
        double x = s * (s-a) * (s-b) * (s-c);
        double area = sqrt(x);
        return area;
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        
        double ans = 0.0;
        int n = points.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    
                    double a = findDis(points[i], points[j]);
                    double b = findDis(points[j], points[k]);
                    double c = findDis(points[k], points[i]);
                    ans = max(ans, findArea(a, b, c));
                }
            }
        }
        return ans;
    }
};