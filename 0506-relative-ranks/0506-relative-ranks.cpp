class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        //Approach-1 (using map ans sorting)
       /* int n = score.size();
        vector<string> result(n);
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[score[i]]=i;
        }

        sort(score.begin(),score.end(),greater<int>());

        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                int ath = mp[score[i]];
                result[ath]="Gold Medal";
            }
            else if(i==1)
            {
                int ath = mp[score[i]];
                result[ath]="Silver Medal";
            }
            else if(i==2)
            {
                int ath = mp[score[i]];
                result[ath]="Bronze Medal";
            }
            else
            {   
                int ath=mp[score[i]];
                result[ath]=to_string(i+1);
            }
        }
        return result;*/
        //Approach-2(using max-heap)
        //T.C=O(nlogn)
        //S.C=O(n)
        int n=score.size();
        vector<string> result(n);
        priority_queue<pair<int,int>> pq;//max_heap
        for(int i=0;i<n;i++)
        {
            pq.push({score[i],i});
        }
        int rank=1;
        while(!pq.empty())
        {
            int idx = pq.top().second;
            pq.pop();

            if(rank==1)
                result[idx]="Gold Medal";
            else if(rank==2)
                result[idx]="Silver Medal";
            else if(rank==3)
                result[idx]="Bronze Medal";
            else
                result[idx]=to_string(rank);
            
            rank++;
        }
        return result;
    }
};