class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        stack<int> st;
        queue<int> q;
        int count=0;
       for(int i=0;i<n;i++)
        {
            st.push(sandwiches[n-i-1]);
            q.push(students[i]);
        }
        while(!st.empty() && !q.empty())  
        {
                if(st.top()==q.front())
                {
                    st.pop();
                    q.pop();
                    count=0;
                }
                else
                {
                    int temp=q.front();
                    q.pop();
                    q.push(temp);//adds the student to the back of the queue.
                    count++;

                    if(count==q.size())
                        break;
                }

        }
    
        return st.size();
    }
};