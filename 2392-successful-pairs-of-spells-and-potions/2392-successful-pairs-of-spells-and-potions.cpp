class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    // Sort the potions array
    sort(potions.begin(), potions.end());
    int m = potions.size();
    vector<int> result;

    // Iterate through each spell
    for (int spell : spells) {
        // Calculate the minimum required potion strength
        long long required = (success + spell - 1) / spell; // Equivalent to ceil(success / spell)
        
        // Find the first potion that satisfies the condition using binary search
        auto it = lower_bound(potions.begin(), potions.end(), required);
        
        // Calculate the number of successful pairs
        result.push_back(potions.end() - it);
    }

    return result;
    }
};