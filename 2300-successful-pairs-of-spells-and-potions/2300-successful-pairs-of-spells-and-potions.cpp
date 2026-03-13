class Solution {
public:
    // find first index where potions[index] >= target
    int binarySearch(vector<int>& potions, int target){

        int left = 0;
        int right = potions.size() - 1;
        int firstValid = potions.size(); // default value

        while(left <= right){

            int mid = left + (right - left)/2;

            if(potions[mid] >= target){
                firstValid = mid; // potential answer
                right = mid - 1;    // search further left for even smaller value
            } else { 
                left = mid + 1; // too small, go right
            }
        }
        return firstValid;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(), potions.end());

        int m = potions.size();
        int maxPotion = potions[m-1]; // largest potion available

        vector<int> ans;

        for(int spell: spells){

            // spell * potion >= success
            // potion >= success / spell
            // minimum potion needed --> potion >= ceil((1.0 * success)/spell);
            long long threshold = ceil((1.0*success) / spell);

            // if even biggest potion(maxPotion) fails, we get 0 pairs
            if(threshold > maxPotion){
                ans.push_back(0);
                continue;

            }
            // binary search -> find the first index where potion >= threshold
            int firstValid = binarySearch(potions, threshold);

            // all potions beyond firstValid i.e from firstValid to end will be valid
            ans.push_back(m - firstValid);
        }
        return ans;
    }
};