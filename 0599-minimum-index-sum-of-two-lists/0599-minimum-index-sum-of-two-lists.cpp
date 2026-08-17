class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        unordered_map<string, int> mp;
        vector<string> result;

       for(int i=0; i<list1.size(); i++){

            mp[list1[i]] = i;
        }

        int minSum = INT_MAX;

        for(int j=0; j<list2.size(); j++){

            if(mp.find(list2[j]) != mp.end()){
                int sum = mp[list2[j]] + j;

                if(sum < minSum){
                    minSum = sum;
                    result.clear();
                    result.push_back(list2[j]);
                } else if(sum == minSum){
                    result.push_back(list2[j]);
                }
            }
        }
        return result;
    }
};