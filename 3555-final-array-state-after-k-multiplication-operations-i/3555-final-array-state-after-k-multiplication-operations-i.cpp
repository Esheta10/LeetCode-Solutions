class Solution {
public:
    #define P pair<int,int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        //Approach-1 (Brute Force)
        //T.C : O(n * k)
        //S.C : O(1)
        /*
        int n = nums.size();

        for(int i=0;i<k;i++)
        {
            int idx=0;
            for(int j=0;j<n;j++)
            {
                if(nums[j] < nums[idx])
                    idx = j;
            }
           nums[idx] *= multiplier;
        }
        return nums;    */

        int n = nums.size();

        priority_queue<P,vector<P>,greater<P>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        while(k--)
        {
            pair<int,int> temp = pq.top();
            pq.pop();

            int number = temp.first;
            int idx = temp.second;

            nums[idx] = number*multiplier;
            pq.push({nums[idx],idx});

        }
        return nums;
    }
};