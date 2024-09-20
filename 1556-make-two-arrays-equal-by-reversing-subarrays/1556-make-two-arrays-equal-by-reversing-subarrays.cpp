class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
//Approach - 1 (Sorting)
//T.C : O(nlogn)
//S.C : O(1)
       /* sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());

        for(int i=0;i<arr.size();i++)
        {
            if(target[i]!=arr[i])
                return false;
        }
        return true;    */
        unordered_map<int,int> mp;
        for(int &num:target)
        {
            mp[num]++;
        }
        for(int &num:arr)
        {
            if(mp.find(num)==mp.end())
                return false;

            mp[num]--;
            if(mp[num]==0)
            {
                mp.erase(num);
            }
        }
        return mp.size()==0;
    }
};