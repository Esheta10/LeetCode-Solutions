class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        
        int n = words.size();

        int result = INT_MAX;
        int straightDistance = -1;
        int circularDistance = -1;
        for(int i=0; i<n; i++){

            if(words[i] == target){
                
                straightDistance = abs(i - startIndex);
                circularDistance = n - straightDistance;

                result = min({result, straightDistance, circularDistance});
            }       
        }
        return result == INT_MAX ? -1 : result;
    }
};