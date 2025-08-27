class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;

            int rowMax = 0;
            for(int i=0;i<m;i++)
            {
                if(mat[i][mid] > mat[rowMax][mid])
                    rowMax = i;
            }

            int left = (mid-1 >= 0) ? mat[rowMax][mid-1] : -1;
            int right = (mid+1 < n) ? mat[rowMax][mid+1] : -1;
            
            if(mat[rowMax][mid] >= left && mat[rowMax][mid] >= right)
                return {rowMax,mid};

            else if(left > mat[rowMax][mid])
                high = mid-1;
            else
                low = mid+1;
        }
        return {-1,-1};
    }
};