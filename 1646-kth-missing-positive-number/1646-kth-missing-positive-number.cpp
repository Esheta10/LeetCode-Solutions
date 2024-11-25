class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //APPROACH-1: Linear Time Complexity
       /* int num=1; // Initialize the number to start checking for missing numbers
        int n=arr.size();// Get the size of the array
        int i=0;  // Index to traverse the input array
        while(i<n && k>0)  // Loop to check for missing numbers in the range covered by the array
        {
            if(arr[i]==num) // If the current number exists in the array, move to the next array element
                i++;
            else  // If the current number is missing, decrement k
                k--;


            num++;
        }
        while(k--)// If there are still missing numbers to find after the array is traversed
        {
            num++;// Increment the number for each remaining missing count
        }
        return num-1;// Return the (k-th missing number) which is one less than the current num*/
        int n=arr.size();
        int l=0,r=n-1;
        int mid=-1;
        while(l<=r)
        {
            mid = l+(r-l)/2;

            int kitne_missing_till_mid = arr[mid] - (mid+1);

            if(kitne_missing_till_mid < k)
                l=mid+1;
            else
                r=mid-1;
        }
        return l+k;
    }
};