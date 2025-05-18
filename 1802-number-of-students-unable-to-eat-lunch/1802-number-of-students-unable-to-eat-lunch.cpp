class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = sandwiches.size(); // Total number of students (same as sandwiches)

        int s_0 = 0; // Count of students who prefer sandwich type 0 (circular)
        int s_1 = 0; // Count of students who prefer sandwich type 1 (square)

        // Count the number of students who prefer each type
        for (int s : students) {
            if (s == 0)
                s_0++; // Increment count for circular preference
            else
                s_1++; // Increment count for square preference
        }

        // Iterate through the sandwich stack
        for (int i = 0; i < n; i++) {
            if (sandwiches[i] == 0) {
                // If no student wants circular sandwiches anymore
                if (s_0 == 0)
                    return n - i; // Remaining students can't eat
                s_0--; // One student with preference 0 eats
            } else {
                // If no student wants square sandwiches anymore
                if (s_1 == 0)
                    return n - i; // Remaining students can't eat
                s_1--; // One student with preference 1 eats
            }
        }

        // All students were able to eat
        return 0;
    }
};
