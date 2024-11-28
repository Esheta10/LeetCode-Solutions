class Solution {
public:
    bool canFormPairs(vector<int>& nums,int max_diff,int p)
    {
        int n = nums.size();
        int pairs = 0;
        
        //greedy pairing strategy
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]-nums[i] <= max_diff)
            {
                pairs++;
                i++;
            }

            //if we already have enough pairs return true
            if(pairs >= p)
                return true;
        }
        //return whether we could at least form p pairs
        return pairs>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        //sort the array
        sort(nums.begin(),nums.end());

        //Binary search for the minimal maximum difference
        int left = 0;
        int right = nums.back()-nums.front();
        int result=right;

        while(left<=right)
        {
            int mid = left + (right-left)/2;
            // Step 3: Check if it's possible to form p pairs with max difference = mid
            if (canFormPairs(nums,mid,p))
            {
                result=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return result;
    }
};