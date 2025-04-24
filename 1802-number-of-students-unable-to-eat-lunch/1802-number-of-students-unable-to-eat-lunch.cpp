class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=sandwiches.size();
        int s_0=0;
        int s_1=0;

        for(int s : students)
        {
            if(s==0)
                s_0++;
            else
                s_1++;
        }
        for(int i=0;i<sandwiches.size();i++)
        {
            if(sandwiches[i]==0)
            {
                if(s_0==0)
                    return n-i;
                s_0--;
            }
            else
            {
                if(s_1==0)
                    return n-i;
                s_1--;
            }

        }
        return 0;
    }
};