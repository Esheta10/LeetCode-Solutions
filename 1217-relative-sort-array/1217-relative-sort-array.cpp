class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;

        for(int i=0;i<arr2.size();i++)
        {
            mp[arr2[i]]=i;//2->0, 1->1, 4->2, 3->3, 9->4, 6->5
        }
        for(int &num : arr1)
        {
            if(!mp.contains(num))
                mp[num]=1e9;//arr1 ke index ki value infinity kar do
        }

        auto lambda = [&](int &num1,int &num2){
            if(mp[num1] == mp[num2])//in case of infinity
                return num1 < num2;//return the lesser of the two values like return 7 before 19
                return mp[num1] < mp[num2];
        };
        sort(arr1.begin(),arr1.end(),lambda);
        return arr1;
    }
};