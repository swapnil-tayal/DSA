class Solution {
public:
    int racecar(int target) {
        
        queue<vector<int>> q;
        q.push({ 0, 1, 0 });

        while(!q.empty()){

            int pos = q.front()[0];
            int speed = q.front()[1];
            int steps = q.front()[2];
            q.pop();

            if(pos == target) return steps;

            if(pos + speed > 0 and pos + speed <= 2*target){
                q.push({ pos + speed, speed * 2, steps + 1 });
            }
            if(speed > 0 and (pos + speed) > target){
                q.push({ pos, -1, steps + 1 });
            }
            if(speed < 0 and (pos + speed) < target){
                q.push({ pos, 1, steps + 1 });
            }
        }
        return -1;
    }
};