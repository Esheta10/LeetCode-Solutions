class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        /* APPROACH-1
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());

        int n = seats.size();
        int moves = 0;
        for(int i=0;i<n;i++)
        {
            moves += abs(seats[i]-students[i]);
        }
        return moves;
        */
        //APPROACH-2
        //int n = students.size();
        vector<int> position_stud(101,0);
        vector<int> position_seat(101,0);

        int i=0,j=0;
        int moves=0;

        for(int &pos : students)
        {
            position_stud[pos]++;
        }
        for(int &pos : seats)
        {
            position_seat[pos]++;
        }
        while(i<=100 && j<=100)
        {
            if(position_stud[i]==0) i++;
            if(position_seat[j]==0) j++;

            if(i<=100 && j<=100 && position_stud[i]!=0 && position_seat[j]!=0)
            {
                moves += abs(i-j);
                position_stud[i]--;
                position_seat[j]--;
               // n--;
            }
        }
        return moves;
    }
};