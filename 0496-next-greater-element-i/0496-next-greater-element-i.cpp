class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        vector<int> result;

        for(int i=0;i<m;++i)
        {
            int foundIndex=-1;
            for(int j=0;j<n;++j)
            {
                // Step 1: Find the index of nums1[i] in nums2
                if(nums2[j] == nums1[i])
                {
                    foundIndex = j;
                    break;
                }        
            }
            // Step 2: Find the next greater element after foundIndex
            int nextGreater=-1;
            for(int k = foundIndex + 1; k<n; ++k)
            {
                if(nums2[k] > nums1[i])
                {
                    nextGreater = nums2[k];
                    break;
                }
            }
            result.push_back(nextGreater);
        }   
        return result;
    }
};