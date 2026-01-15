class Solution {
public:
    bool hasCycle = false;
    void DFS(unordered_map<int,vector<int>>& adj, int u, stack<int>& st, vector<bool>& visited, vector<bool>& inRecursion){

        visited[u] = true;
        inRecursion[u] = true;

        // pehle mere baccho ko daalo( u ke)
        for(int &v: adj[u]){

            if(inRecursion[v] == true){
                hasCycle = true;
                return;
            }
            if(!visited[v])
                DFS(adj,v,st,visited,inRecursion);
        }
        // fir mujhe daalo
        st.push(u);
        inRecursion[u] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;

        vector<bool> inRecursion(numCourses, false);
        vector<bool> visited(numCourses, false);

        for(auto &vec: prerequisites){

            int a = vec[0];
            int b = vec[1];

            // b-->a 
            adj[b].push_back(a);

           
        }

        stack<int> st;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                DFS(adj,i,st,visited,inRecursion);
            }
        }

        if(hasCycle)
            return {};

        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};