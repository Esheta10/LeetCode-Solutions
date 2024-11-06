class Solution {
public:
    string orderlyQueue(string s, int k) {
        //simply sort and retirn if k>1
        if(k>1)
        {
            sort(s.begin(),s.end());
        }
        string result = s;
        for(int i=1;i<=s.size()-1;i++)
        {
            string temp = s.substr(i) + s.substr(0,i);
            result = min(result,temp);
        }
        return result;
    }
};