class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Heapify - O(n)
        priority_queue<int> pq(gifts.begin(),gifts.end());  //max-heap
        long long sum = 0;
        for(int &gift : gifts)  //O(n)
            sum += gift;

        int maxEle = 0;
        while(k--)  //O(k)
        {
            maxEle = pq.top();  //O(1)
            pq.pop();//O(log(n))

            int remaining = sqrt(maxEle);
            sum -= (maxEle - remaining);
            pq.push(remaining);
        }
        return sum;
    }
};