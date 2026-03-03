class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;
    int kadane(vector<int>& arr){

        int n = arr.size();
        int curr_sum = arr[0];
        int max_sum = arr[0];

        for(int i=1; i<n; i++){

            curr_sum = max(curr_sum + arr[i], arr[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        int totalSum = 0;

        for(int num: arr)
            totalSum += num;

        vector<int> twoCopies;
        for(int i=0; i<min(k,2); i++){  // if k=1, build only 1 copy 
            for(int num: arr)
                twoCopies.push_back(num);
        }

        long long best = kadane(twoCopies);

        if(totalSum > 0 && k>2)
            best += (k-2ll) * totalSum;

        return max(best,0ll) % MOD; // empty subarray has sum 0 and if the value leans on the negative side, return 0
    }
};