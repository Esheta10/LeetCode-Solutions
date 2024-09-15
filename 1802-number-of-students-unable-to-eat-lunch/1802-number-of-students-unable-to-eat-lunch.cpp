class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
      /*APPROACH-1  int n=students.size();
        stack<int> st;
        queue<int> q;
        int count=0;
       // Initialize stack and queue
       for(int i=0;i<n;i++)
        {
            st.push(sandwiches[n-i-1]);// Fill stack with sandwiches
            q.push(students[i]);// Fill queue with students
        }
        while(!st.empty() && !q.empty())  
        {
                if(st.top()==q.front())
                {
                    st.pop();
                    q.pop();
                    count=0;// Reset count when a sandwich is eaten
                }
                else
                {
                    int temp=q.front();
                    q.pop();
                    q.push(temp);//adds the student to the back of the queue.
                    count++;

                    if(count==q.size())// No student can eat the current sandwich
                        break;
                }

        }
    
        return st.size();// Return the number of uneaten sandwiches*/
        int n = students.size();
        int arr[2]={0};
        //arr[0]->count of students liking 0 sandwich
        //arr[1]->count of students liking 1 sandwich
        for(int &stud:students)
        {
            arr[stud]++;
        }
        for(int i=0;i<n;i++)
        {
            int sand=sandwiches[i];
            if(arr[sand]==0)
                return n-i;

            arr[sand]--;

        }
        return 0;
    }
};