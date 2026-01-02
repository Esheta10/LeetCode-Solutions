//Approach-1 (Using Hashset)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;
        
        for (int &num : nums) {
            if(st.count(num))
                return num;
            
            st.insert(num);
        }
        
        return -1;
    }
};