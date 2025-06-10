class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //Approach-1: using map
        //T.C=O(n)
        //S.C=O(n)
        /*
        unordered_map<int,int> degree;
        for(auto &vec:edges)
        {
            int u = vec[0];
            int v = vec[1];

            degree[u]++;
            degree[v]++;
        }
        for(auto &it:degree)
        {
            if(it.second==edges.size())
                return it.first;
        }
        return -1;
        */
        //Approach-2(constant time)
        //T.C.=O(1)
        //S.C.=O(1)
        vector<int> first = edges[0];   //{a,b}
        vector<int> second = edges[1];  //{c,a}

        if(first[0]==second[0] || first[0]==second[1])
            return first[0];

        return first[1];

    }
};