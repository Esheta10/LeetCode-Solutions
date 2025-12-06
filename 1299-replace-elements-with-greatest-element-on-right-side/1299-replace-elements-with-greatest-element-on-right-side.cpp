class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int n = arr.size();

        vector<int> result(n);
        result[n-1] = -1;

        int maxFromRight = arr[n-1];

        for(int i=n-2; i>=0; i--){

            result[i] = maxFromRight;
            maxFromRight = max(maxFromRight, arr[i]);
        }
        return result;
    }
};