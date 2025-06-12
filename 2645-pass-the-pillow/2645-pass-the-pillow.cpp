class Solution {
public:
    int passThePillow(int n, int time) {
        //Approach-1(Simulations)
        //T.C. = O(time)
        //S.C. = O(1)
        /*
        int idx = 1;
        int dir = 1;
        while(time > 0)
        {
            if(idx+dir >= 1 && idx+dir <= n)
            {
                idx += dir;
                time--;
            }
            else
                dir *= -1;
        }
        return idx;
        */
        int fullRounds = time/(n-1);
        int timeLeft = time%(n-1);

        if(fullRounds % 2==0)
            return timeLeft+1;//you are at first position
        else
            return n-timeLeft;


        return -1;
    }
};