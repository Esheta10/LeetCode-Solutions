class Solution {
public:
    int BinarySearch(int l,int r,vector<int>& potions,int minPotion)
    {
        int index = -1;
        int mid=0;

        while(l<=r)
        {
            mid = l+(r-l)/2;
            if(potions[mid]>=minPotion)
            {
                index=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return index;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //Approach-1 : Using lower_bound STL
        /*int m = spells.size();
        int n = potions.size();

        sort(potions.begin(),potions.end());

        vector<int> answer;
        int maxPotion=potions[n-1];

        for(int i=0;i<m;i++)
        {
            int spell=spells[i];
            long long minPotion = ceil((1.0*success)/spell);

            if(minPotion > maxPotion)
            {
                answer.push_back(0);
                continue;
            }
            int index = lower_bound(begin(potions),end(potions),minPotion)-begin(potions);
//It performs a binary search to find the first position in the sorted range [begin(potions), end(potions)) where the value is not less than minPotion.
            answer.push_back(n-index);
        }
        return answer;*/
        int m = spells.size();
        int n = potions.size();

        vector<int> answer;
        sort(potions.begin(),potions.end());
        int maxPotion = potions[n-1];

        for(int i=0;i<m;i++)
        {
            int spell=spells[i];
            long long minPotion = ceil((1.0*success)/spell);

            if(minPotion > maxPotion)
            {
                answer.push_back(0);
                continue;
            }
            int index = BinarySearch(0,n-1,potions,minPotion);
            
            answer.push_back(n-index);
        }
        return answer;
    }
};