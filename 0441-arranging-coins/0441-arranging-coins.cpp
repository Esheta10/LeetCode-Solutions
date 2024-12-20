class Solution {
public:
    int arrangeCoins(int n) {
        long long left=0,right=n;
        while(left<=right)
        {
            long long mid = left+(right-left)/2;
            long long total_coins = mid*(mid+1)/2;

            if(total_coins==n)
                return mid;
            else if(total_coins < n)
                left=mid+1;
            else
                right=mid-1;
        }
        return right; // The largest k where total_coins <= n
    }
};