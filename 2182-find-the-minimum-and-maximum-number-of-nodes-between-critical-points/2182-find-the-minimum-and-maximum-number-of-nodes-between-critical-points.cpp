/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       int min_Distance = INT_MAX;
        int i = 1; // current position index (start from the second node)
        int prevCriticalIndex = -1; // to store previous critical point index
        int firstCriticalIndex = -1; // to store the first critical point index
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr && curr->next) {
            // Check if the current node is a critical point (local min or max)
            if ((curr->val < prev->val && curr->val < curr->next->val) || 
                (curr->val > prev->val && curr->val > curr->next->val)) {
                
                // First critical point
                if (firstCriticalIndex == -1) {
                    firstCriticalIndex = i;
                }
                
                // Calculate min distance if it's not the first critical point
                if (prevCriticalIndex != -1) {
                    min_Distance = min(min_Distance, i - prevCriticalIndex);
                }
                
                prevCriticalIndex = i; // Update the previous critical point index
            }

            // Move the pointers to the next nodes
            prev = curr;
            curr = curr->next;
            i++;
        }

        // If fewer than two critical points were found
        if (firstCriticalIndex == -1 || prevCriticalIndex == firstCriticalIndex) {
            return {-1, -1};
        }

        // max_Distance is the distance between the first and last critical point
        int max_Distance = prevCriticalIndex - firstCriticalIndex;
        
        return {min_Distance, max_Distance};
    }
};