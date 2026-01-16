class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto &time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v,w});
        }

        // min heap
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // result array
        vector<int> result(n+1, INT_MAX);
      
        // visited array
        vector<bool> visited(n+1, false);

        result[k] = 0;
        pq.push({0,k});

        // Dijkstra's Algorithm

        while(!pq.empty()){

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(visited[node])
                continue;

            if(!visited[node])
                visited[node] = true;

            for(auto &neighbor : adj[node]){

                int adjNode = neighbor.first;
                int wt = neighbor.second;

                if(!visited[adjNode] && d+wt < result[adjNode]){

                    result[adjNode] =  d+wt;
                    pq.push({d+wt, adjNode});
                }
            } 

        }
        int maxTime = 0;
        for(int i=1; i<=n; i++){
            if(result[i] == INT_MAX)
                return -1;

            maxTime = max(maxTime, result[i]);
        }
       return maxTime;
    }
};