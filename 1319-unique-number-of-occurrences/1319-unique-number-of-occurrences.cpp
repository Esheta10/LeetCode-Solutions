class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    /*APPROACH-1
        unordered_map<int,int> mp;
        //store frequency of each numbers
        for(int &num:arr)
            mp[num]++;

        unordered_set<int> st;
        for(auto it:mp)
        {
            int freq = it.second;//it.first = number;
            if(st.find(freq)!=st.end())
                return false;

             st.insert(freq);
               
        }
        return true;    */
        vector<int> vec(2001,0);
        for(int &x:arr)
            vec[x+1000]++;

        sort(vec.begin(),vec.end());

        for(int i=1;i<2001;i++)
        {
            if(vec[i]!=0 && vec[i]==vec[i-1])
                return false;
        }
        return true;
    }
};