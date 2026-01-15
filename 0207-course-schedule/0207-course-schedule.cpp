class Solution {
public:
    bool topologicalSort(unordered_map<int,vector<int>>& adj, int n, vector<int>& indegree){

        queue<int> que;
        int count = 0;
        for(int i=0; i<n;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
            }
        }

        while(!que.empty()){

            int u = que.front();
            que.pop();

            for(int &v : adj[u]){

                indegree[v]--;

                if(indegree[v]==0){
                    que.push(v);
                    count++;
                }
            }
        }
        if(count == n)  // I was able to visit all nodes and complete the course
            return true; // no cycle

        return false; // means there was a cycle and I couldn't complete all courses
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;

        vector<int> indegree(numCourses,0);    // visited check(Kahn's Algo)


        for(auto& vec: prerequisites){
            int a = vec[0];
            int b = vec[1];

            // b--->a
            adj[b].push_back(a);

            // arrow --> jaa raha hai 'a' mein
            indegree[a]++;
        }

        // if cycle present, not possible
        return topologicalSort(adj, numCourses, indegree);
    }
};