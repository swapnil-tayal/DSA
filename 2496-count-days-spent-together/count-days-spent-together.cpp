class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int monthAlice = stoi(arriveAlice.substr(0, 2));
        int dayAlice = stoi(arriveAlice.substr(3, 2));
        int monthBob = stoi(arriveBob.substr(0, 2));
        int dayBob = stoi(arriveBob.substr(3, 2));

        int monthAliceLeave = stoi(leaveAlice.substr(0, 2));
        int dayAliceLeave = stoi(leaveAlice.substr(3, 2));
        int monthBobLeave = stoi(leaveBob.substr(0, 2));
        int dayBobLeave = stoi(leaveBob.substr(3, 2));

        vector<int> a = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int cnt = 0;

        for(int i=monthAlice; i<=monthAliceLeave; i++){

            int start = (i == monthAlice ? dayAlice : 1);
            int end = (i == monthAliceLeave ? dayAliceLeave : a[i]);

            for(int j=start; j<=end; j++){
                
                if(i >= monthBob and i <= monthBobLeave){
                    if(i == monthBobLeave and i == monthBob) cnt += (j <= dayBobLeave && j >= dayBob);
                    else if(i == monthBobLeave) cnt += (j <= dayBobLeave);
                    else if(i == monthBob) cnt += (j >= dayBob);
                    else cnt++;
                }
            }
        }
        return cnt;
    }
};