class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
      /*APPROACH-1
        int result=0;
        int m=mat.size();
        int n=mat[0].size();

        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(mat[row][col]==0)
                    continue;

                bool special=true;
                //check column
                for(int r=0;r<m;r++)
                {
                    if(r!=row && mat[r][col]==1)
                    {
                        special=false;
                        break;
                    }
                }
                //check row
                for(int c=0;c<n;c++)
                {
                    if(c!=col && mat[row][c]==1)
                    {
                        special=false;
                        break;
                    }
                }
                if(special==true)
                    result++;
            }
        }
        return result;*/
        int result=0;
        int m=mat.size();
        int n=mat[0].size();
        vector<int> rowCount(m,0);//how many 1s in a row
        vector<int> colCount(n,0);//how many 1s in a column
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(mat[row][col]==1)
                {
                    rowCount[row]++;
                    colCount[col]++;
                }
                
            }
        }
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(mat[row][col]==0)
                    continue;

                if(rowCount[row]==1 && colCount[col]==1)
                    result++;
            }
        }
        return result;
    }
};