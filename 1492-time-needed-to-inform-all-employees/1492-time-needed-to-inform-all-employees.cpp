class Solution {
public:
    int max_time = INT_MIN;
    void DFS(unordered_map<int,vector<int>>& adj, vector<int>& informTime,int curr_employee,int curr_time)
    {
        max_time = max(max_time,curr_time);
        for(int & employee: adj[curr_employee])
        {
            DFS(adj, informTime, employee, curr_time + informTime[curr_employee]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<manager.size();i++)
        {
            int child = i ;
            int manager_i = manager[i];

            if(manager_i != -1)
                adj[manager_i].push_back(child);
        }

        DFS(adj,informTime,headID,0);

        return max_time;
    }
};