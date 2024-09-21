class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
//Approach-1 (Using simply simulation)
//T.C : O(m*n)
//S.C : O(1) //no including space of result       
    /*  vector<vector<int>> result(m,vector<int>(n));
        int l=original.size();

        if(l != m*n)
        {
            return {};
        }
        int idx=0;
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                result[row][col]=original[idx];
                idx++;
            }
        }
        return result; */
         vector<vector<int>> result(m, vector<int>(n));
         int l=original.size();
         if(l!=m*n)
         {
            return {};
         }
        
         for(int i=0;i<l;i++)
         {
            result[i/n][i%n]=original[i];
         }
         return result;
    }
};
