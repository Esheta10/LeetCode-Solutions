class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //APPROACH-1
        /* unordered_set<int> st1(nums1.begin(),nums1.end());
        unordered_set<int> st2;
        
        for(int &num: nums2)
        {
            if(st1.find(num)!=st2.end())
                st2.insert(num);
        }
        vector<int> result;
        for(auto &it:st2)
        {
            result.push_back(it);
        }
        return result;  */
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int m = nums1.size();
        int n = nums2.size();

        int i=0;//nums1
        int j=0;//nums2

        vector<int> result;
        while(i<m && j<n)
        {
            if(nums1[i]==nums2[j])
            {
                  result.push_back(nums1[i]);//nums2[j]

                  while(i<m-1 && nums1[i]==nums1[i+1])
                    i++;
                  while(j<n-1 && nums2[j]==nums2[j+1])
                    j++;

                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
                i++;
            else
                j++;
        }
        return result;
    }
};