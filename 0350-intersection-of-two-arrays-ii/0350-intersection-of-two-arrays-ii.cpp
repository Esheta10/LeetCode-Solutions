class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       /*APPROACH-1
       //T.C:  O(n)
       //S.C : O(n)
        unordered_map<int,int> mp;
        for(int &num : nums1)
        {
            mp[num]++;
        }
        vector<int> result;
        for(int i=0;i<nums2.size();i++)
        {
            int num = nums2[i];
            if(mp[num]>0)
            {
                mp[num]--;//dobara agar woh number fir se aata hai tb hum use again result mein nahi add karenge
                result.push_back(num);
            }
        }
        return result;*/
        /*APPROACH-2*/
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;// -> nums1
        int j=0;// -> nums2
        vector<int> result;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                result.push_back(nums1[i]);//result.push_back(nums2[j]);
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
//T.C:  O(n)
//S.C : O(n)