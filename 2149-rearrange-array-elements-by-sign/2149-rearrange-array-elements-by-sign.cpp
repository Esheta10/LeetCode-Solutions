class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> pos,neg;
        int i=0,j=0;
        vector<int> res;


        for(int num : nums){
            if(num>0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        while(i<pos.size() && j<neg.size()){
            res.push_back(pos[i++]);
            res.push_back(neg[j++]);
        }

        while(i<pos.size()) res.push_back(pos[i++]);
        while(j<neg.size()) res.push_back(neg[j++]);

        return res;
    }
};