class Solution {
public:
    int passThePillow(int n, int time) {
        int idx = 1;//position of illow
        int dir=1;//L to R
        
        while(time>0)
        {
            if((idx+dir)>=1 && (idx+dir)<=n)
            {
                idx += dir;
                time--;
            }
            else
            {
                dir *= -1;
            }
        }
        return idx;
    }
};