class Solution {
public:
    bool sumGame(string num) {

        int sum1 = 0;
        int sum2 = 0;
        int q1 = 0;
        int q2 = 0;
        int n = num.size();

        for(int i=0; i<n/2; i++){
            if(num[i] == '?') q1++;
            else sum1 += (num[i] - '0');
        }
        for(int i=n/2; i<n; i++){
            if(num[i] == '?') q2++;
            else sum2 += (num[i] - '0');
        }
        if(q1 == q2) return sum1 != sum2;

        int mini = min(q1, q2);
        q1 -= mini;
        q2 -= mini;
        if(q2 < q1){
            swap(q1, q2);
            swap(sum1, sum2);
        }
        int bobMaxScore = 0;
        int aliceMaxScore = 0;
        // if(mini % 2 == 0) 
        bobMaxScore = (q2/2) * 9;
        // else bobMaxScore = ((q2+1)/2) * 9;
        // if(mini % 2 == 0) 
        aliceMaxScore = ((q2+1)/2) * 9;
        // else aliceMaxScore = (q2/2) * 9;

        cout<<bobMaxScore<<' '<<aliceMaxScore<<' '<<sum1<<' '<<sum2<<'\n';

        if(sum1 > sum2 + bobMaxScore) return true;
        if(sum1 < sum2 + aliceMaxScore) return true;
        // if(sum1 == sum2 + aliceMaxScore + bobMaxScore) return true;
        return false;
    }
};

// 905? ?8?6
// 14   14