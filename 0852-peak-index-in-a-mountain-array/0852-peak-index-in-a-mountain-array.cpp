class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int peak = *max_element(arr.begin(), arr.end());

        int n = arr.size();

        for(int i=0; i<n; i++){

            if(peak == arr[i])
                return i;
        }
        return -1;
    }
};