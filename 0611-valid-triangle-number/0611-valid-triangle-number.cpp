class Solution {
public:
    int triangleNumber(vector<int>& nums) {
         int n = nums.size();
    int count = 0;

    // Sort the array to make checking easier
    sort(nums.begin(), nums.end());

    // Iterate through each element as the largest side
    for (int k = 2; k < n; ++k) {
        int i = 0, j = k - 1;

        // Use two pointers to find pairs of sides
        while (i < j) {
            // If nums[i] + nums[j] > nums[k], we can form a triangle
            if (nums[i] + nums[j] > nums[k]) {
                count += (j - i); // All pairs between i and j form valid triangles with nums[k]
                j--; // Move j to the left to check for other pairs
            } else {
                i++; // Move i to the right if the sum is too small
            }
        }
    }

    return count;
    }
};