class Solution {
public:
    int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        unordered_map<int,long long> mp;

        mp[arr[0]]=1; // Initialize each element as a tree by itself
        for(int i=1;i<n;i++)
        {
            long long count = 1;
            for(int j=0;j<i;j++)
            {
                int LC = arr[j];
                //RC=arr[i]/LC
                if(arr[i]%LC==0 && mp.find(arr[i/LC])!=mp.end())
                {
                        count += (mp[LC] * mp[arr[i]/LC]);
                }
            }
             mp[arr[i]]=count;
        }
       
        int result = 0;
        //map-->{value,no. of ways to create binary tree}
        for(auto &it : mp)
        {
            //it.first->value(root)
            //it.second->ways
            result = (result + it.second)%MOD;
        }
        return result;
    }
};