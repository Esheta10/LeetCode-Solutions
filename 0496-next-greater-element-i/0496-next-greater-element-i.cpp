class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;

        for(int i=0; i < nums1.size(); i++){

            // step-1 : nums2[j] mein nums1[i] dhundho
            int j = 0;
            while(nums2[j] != nums1[i])
                j++;

            // step-2 : j ke right mein pehla bada element dhundho
            int nextGreater = -1;
            for(int k = j+1; k<nums2.size(); k++){

                if(nums2[k] > nums1[i]){
                    nextGreater = nums2[k];
                    break;
                }
            }
            ans.push_back(nextGreater);
        }
        return ans;
    }
};