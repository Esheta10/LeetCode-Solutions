class Solution {
public:
    vector<int> topologicalSort(unordered_map<int,vector<int>>& adj, int n, vector<int>& indegree){

        queue<int> que;

        int count = 0;

        vector<int> result;

        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                que.push(i);
                result.push_back(i);
                count++;
            }
        }

        while(!que.empty()){

            int u = que.front();
            que.pop();

            for(int &v: adj[u]){

                indegree[v]--;

                if(indegree[v]==0){
                    que.push(v);
                    count++;
                    result.push_back(v);
                }
            }
        }   

        if(count == n)
            return result; // all nodes are visited-> no cycle

        return {};// there's a cycle
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indegree(numCourses, 0);

        unordered_map<int,vector<int>> adj;

        for(auto &vec: prerequisites){

            int a = vec[0];
            int b = vec[1];

            // b-->a
            adj[b].push_back(a);

            // arrow --> a ki taraf aa raha hai
            indegree[a]++;
        } 

        return topologicalSort(adj, numCourses, indegree);
    }
};