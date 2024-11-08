class Solution {
public:
    int compareVersion(string version1, string version2) {
        // Split version1 and version2 by "."
        stringstream ss1(version1),ss2(version2);
        string token="";
        vector<int> v1,v2;
 // Split version1 by "."
        while (getline(ss1,token,'.'))
        {
            v1.push_back(stoi(token));// Convert each part to integer
        }
 // Split version2 by "."
        while (getline(ss2,token,'.'))
        {
            v2.push_back(stoi(token));// Convert each part to integer
        }
         // Compare the parts of version1 and version2
        int n=max(v1.size(),v2.size());
        for(int i=0;i<n;i++)
        {
            int val1 = (i<v1.size() ? v1[i] : 0);// If v1 has no more parts, assume 0
            int val2 = (i<v2.size() ? v2[i] : 0);// If v2 has no more parts, assume 0

            if(val1<val2)
                return -1;// version1 < version2
            if(val1>val2)
                return 1;// version1 > version2
        }
        return 0; // Both versions are equal

    }
};