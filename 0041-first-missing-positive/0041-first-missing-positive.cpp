class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=0; i<n; i++){

            while(true){

                int current = nums[i];

                if(current<1 || current>n)
                    break;

                int rightPlace = current-1;

                if(nums[rightPlace] == current)
                    break; // element apni sahi jagah par hai

                swap(nums[rightPlace], nums[i]);
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};