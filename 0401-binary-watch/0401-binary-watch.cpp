class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for(int hour=0;hour<12;++hour)
        {
            for(int minute=0;minute<60;++minute)
            {
                if(__builtin_popcount(hour)+__builtin_popcount(minute)==turnedOn)
                {
                    stringstream ss;
                    ss<<hour<<":"<<(minute<10 ? "0":"")<<minute;
                    result.push_back(ss.str());
                }
            }
        }
        return result;
    }
};