class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size(); // no. of rows
        int m = heights[0].size(); // no.of columns

        // priority queue {effort, row, col}
        // min-heap: smallest effort comes out first

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // effort array: min-effort to reach each cell
        // Initialize with INT_MAX(infinity)
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

        // 4 directions: up, down, left, right
        vector<pair<int,int>> directions = {
            {-1,0}, {0,-1}, {0,1}, {1,0}
        };

        pq.push({0,0,0}); // start with effort = 0 at (0,0)
        effort[0][0] = 0;

        while(!pq.empty()){

            auto curr = pq.top();
            pq.pop();

            int currEffort = curr[0];   // current effort
            int row = curr[1];  // current row
            int col = curr[2];  // current column

            if(row == n-1 && col == m-1)
                return currEffort; // check if reached destination

                if(currEffort > effort[row][col])
                    continue;   // skip if this is an outdated path

                for(auto &dir : directions){
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    if(newRow<0 || newRow>=n || newCol<0 || newCol>=m)
                        continue;

                    int heightsDiff = abs(heights[row][col] - heights[newRow][newCol]);
                    
                    // maximum jump in entire path
                    int newEffort = max(currEffort, heightsDiff);

                    if(newEffort < effort[newRow][newCol]){
                        effort[newRow][newCol] = newEffort;
                        pq.push({newEffort, newRow, newCol});
                    }
                }
        }
        return 0;
    }
};