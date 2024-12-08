class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         // Check if the input is empty
        if (intervals.empty()) return {};

        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());

        // Result vector to store merged intervals
        vector<vector<int>> result;

        // Initialize with the first interval
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // Get the last interval in the result
            vector<int>& last = result.back();

            // Check if the current interval overlaps with the last one
            if (intervals[i][0] <= last[1]) {
                // Merge intervals by updating the end time
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap, add the current interval to the result
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};