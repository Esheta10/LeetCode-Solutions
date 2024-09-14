class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
       /* unordered_set<int> st(nums1.begin(),nums1.end());
        for(int &num:nums2)
        {
            if(st.find(num)!=st.end())
                return num;
        }
        return -1;*/
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int num:nums1)
        {
            if(binarySearch(nums2,num))
            {
                 return num;
            }
        }
        return -1;
    }
private:
     bool binarySearch(vector<int>&nums,int target)
        {
            int l=0,r=nums.size()-1;
            while(l<=r)
            {
                int mid = l+(r-l)/2;
                if(nums[mid]==target)
                    return true;
                else if(nums[mid]>target)
                    r=mid-1;
                else
                    l=mid+1;
            }
            return false;
        }
};