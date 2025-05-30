class Solution {
public:
    int N;

    int solve(int i, int k, int currRate, vector<int>& position, vector<int>& time, vector<vector<vector<int>>>& t) {
        if(i == N-1) {
            if(k > 0) {
                return INT_MAX;
            }
            return 0;
        }

        if(t[i][k][currRate] != -1) {
            return t[i][k][currRate];
        }

        int result = INT_MAX;

        //skip and no merge
        int skipResultTime = solve(i+1, k, time[i+1], position, time, t);
        if(skipResultTime != INT_MAX) {
            int dist           = position[i+1] - position[i];
            result             = min(result, dist*currRate + skipResultTime);
        }


        //We decide to merge
        if(k > 0) {
            int mergeTime  = time[i+1];
            int mergeCount = 0;
          
            //i ---- i+1 ------ i+2 ------- i+3 .....
            //If we merge i+1 and i+2
            //i ---------- i+2 -------- i+3 , then you see (i+1) disappeared and 1 merge required

            //What if we want i -------- i+3 ???
            //We will need 2 merges i.e. merge i+1 to i+2 and i+2 to i+3, meaning we need two merges
            // i ------ i+3 .......

            //This for loop does that. It first tries to connect i to i+2, then i+3 and so on and
            //keeps checking how many merges required and also keep calculating the time required to find minimum
          
            for(int j = i+2; j < N && mergeCount < k; j++) {
                mergeCount++;
                mergeTime += time[j];
                //i -------> j
                int mergeResultTime = solve(j, k - mergeCount, mergeTime, position, time, t);
                if(mergeResultTime != INT_MAX) {
                    int dist = position[j] - position[i];
                    result = min(result, dist*currRate + mergeResultTime);
                }
            }
        }

        return t[i][k][currRate] = result;
    }

    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        N = n;

        int cummulativeTime = 0;
        for(int &t : time) {
            cummulativeTime += t;
        }

        vector<vector<vector<int>>> t(n, vector<vector<int>>(k+1, vector<int>(cummulativeTime+1, -1)));

        return solve(0, k, time[0], position, time, t);
    }
};
