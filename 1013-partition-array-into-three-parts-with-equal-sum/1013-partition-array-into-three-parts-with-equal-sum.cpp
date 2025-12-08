class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
        int n =arr.size();

        int totalSum = 0;
        for(int num : arr){
            totalSum += num;
        }

        int targetSum = totalSum / 3;
        if(totalSum % 3 != 0)
            return false;

        int i=-1,j=-1;
        int currentSum = 0;
        for(int k=0; k<n-2; k++){
            currentSum += arr[k];
            if(targetSum == currentSum){
                i = k;
                break;
            }
        }

        if(i == -1)
            return false;

        currentSum=0;
        for(int k=i+1;k<n-1;k++){
            currentSum += arr[k];
            if(targetSum==currentSum){
                j = k;
                break;
            }
        }

        if(j == -1){
            return false;
        }

        return true;

    }
};