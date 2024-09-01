class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> indexed_nums;
        for(int i=0;i<nums.size();++i)
        {
            indexed_nums.push_back({nums[i],i});
        }
        sort(indexed_nums.begin(),indexed_nums.end(),greater<pair<int,int>>());
 vector<pair<int,int>> top_k_elements(indexed_nums.begin(),indexed_nums.begin()+k);
 sort(top_k_elements.begin(),top_k_elements.end(),[](const pair<int,int>&a,const pair<int,int>&b)
 {
    return a.second<b.second;
 });
 vector<int> result;
 for(const auto& p:top_k_elements)
 {
    result.push_back(p.first);
 }
 return result;
    }

};