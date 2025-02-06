class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map<int, int> pairs;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pairs[nums[i] * nums[j]] += 1;
            }
        }
        int count = 0;
        for (auto it : pairs) {
            int size = it.second;
            if (size > 1) count += (4 * size * (size - 1));
        }
        return count;
    }
};