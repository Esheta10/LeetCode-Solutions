class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result;
        
        vector<int> pos;
        vector<int> neg;
        for(int num: nums){

            if(num> 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        int i=0, j=0;
        while(i<pos.size() && j<neg.size()){
            
            result.push_back(pos[i++]);
            result.push_back(neg[j++]);
        }

        // for remaining elements in either pos and neg arrays
        while(i<pos.size())
            result.push_back(pos[i++]);
        while(j<neg.size())
            result.push_back(neg[j++]);

        return result;
    }
};