class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
     /* APPROACH - 1 
        int n=grid.size();
        int count = 0;
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<n;c++)
            {
                bool isEqual=true;
                for(int i=0;i<n;i++)
                {
                    if(grid[r][i]!=grid[i][c])
                    {
                        isEqual=false;
                        break;
                    }
                }
                if(isEqual==true)
                    count++;
            }
        }
        return count;*/
        int n = grid.size();
        int count = 0;
        //1
        map<vector<int>,int> mp;
        for(int row=0;row<n;row++)
        {
            mp[grid[row]]++;
        }
        //2
        for(int c=0;c<n;c++)
        {
            vector<int> temp;
            for(int r=0;r<n;r++)
            {
                temp.push_back(grid[r][c]);
            }
            count += mp[temp];
        }
        return count;
    }
};