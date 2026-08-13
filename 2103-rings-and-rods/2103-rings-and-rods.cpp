class Solution {
public:
    int countPoints(string rings) {
        
        // rodIndex, color values -> to be counted only once in case of same duplicate colours
        unordered_map<int, unordered_set<char>> mp;

        for(int i=0; i<rings.size(); i+=2){

            int color = rings[i];
            int rodIndex = rings[i+1] - '0';

            mp[rodIndex].insert(color); // rod ke set mein colour insert kar rahe
        }

        int count = 0;
        for(auto &pair: mp){

            if(pair.second.size() == 3)
                count++;
        }
        return count;
    }
};