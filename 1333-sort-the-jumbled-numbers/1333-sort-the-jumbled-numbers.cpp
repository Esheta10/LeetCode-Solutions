class Solution {
public:
    string getMappedNum(string &num, vector<int> &mapping)
    {
        string mappedNum="";
        for(int i=0;i<num.length();i++)
        {
            char ch= num[i];
            mappedNum += to_string(mapping[ch-'0']);
        }
        return mappedNum;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> vec;
//this loop iterates over each number in nums to convert it using  mapping
        for(int i=0;i<n;i++)
        {
            string numStr = to_string(nums[i]);//converts the current number to string form
            string mappedStr = getMappedNum(numStr,mapping);//getting the mapped version of number as a string 
            int mappedNum=stoi(mappedStr);//converts mappedStr back to an integer mappedNum

            vec.push_back({mappedNum,i});
        }
        sort(vec.begin(),vec.end());
        vector<int> result;

        for(auto &p:vec)
        {
            int OriginalNumIdx=p.second;
            result.push_back(nums[OriginalNumIdx]);
        }
        return result;
    }
};