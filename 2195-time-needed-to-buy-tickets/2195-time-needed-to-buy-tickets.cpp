class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        /*APPROACH-1 :(Using Array for simulation)*/
        //T.C : O(m*n) - Outer loop will run until nums[k] is 0. So in worst case nums[k] has max value m 
        //S.C : O(1)
        int n = tickets.size();
        int time = 0;
        
        if(tickets[k]==1)
            return k+1;

        while(tickets[k]>0)
        {
            for(int i=0;i<n;i++)
            {
                if(tickets[i]!=0)
                {
                    tickets[i]--;
                    time++;
                }
                if(tickets[k]==0)
                return time;
            }
        }
        return time;
        /*APPROACH-2: Simple Observation
        //T.C : O(n)
        //S.C : O(1)
        int time=0;
        for(int i=0;i<tickets.size();i++)
        {
            if(i<=k)
                 time += min(tickets[i],tickets[k]);
            else
                 time += min(tickets[k]-1,tickets[i]);
        }
        return time;*/
    }
};