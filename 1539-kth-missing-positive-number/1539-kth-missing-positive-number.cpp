class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        int num = 1;
        int i=0;

        while(i<n && k>0){

            if(arr[i] == num)
                i++;
            else
                k--;


            num++;
        }

        // if all the numbers are present and in order like {1,2,3} but k=2, so here we'll take 5 as the missing number
        while(k--)
            num++;

        return num-1;
    }
};