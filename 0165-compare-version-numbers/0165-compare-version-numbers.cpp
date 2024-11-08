class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1),ss2(version2);
        string token="";
        vector<int> v1,v2;

        while (getline(ss1,token,'.'))
        {
            v1.push_back(stoi(token));
        }
        while (getline(ss2,token,'.'))
        {
            v2.push_back(stoi(token));
        }
        int n=max(v1.size(),v2.size());
        for(int i=0;i<n;i++)
        {
            int val1 = (i<v1.size() ? v1[i] : 0);
            int val2 = (i<v2.size() ? v2[i] : 0);

            if(val1<val2)
                return -1;
            if(val1>val2)
                return 1;
        }
        return 0;
    }
};