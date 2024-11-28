// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1;
        int right=n;
        while(left<right)
        {
            int mid=left+(right-left)/2;

            if (isBadVersion(mid))
            {
                right=mid; // first bad version is at mid or before
            }
            else
            {
                left=mid+1; // first bad version is after mid
            }
        }
        return left;// left will point to the first bad version
    }
};