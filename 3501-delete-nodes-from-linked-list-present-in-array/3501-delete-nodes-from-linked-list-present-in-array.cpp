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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
       
       unordered_set<int> st(nums.begin(),nums.end());

     // Dummy node to handle edge cases easily (e.g., head being removed)
       ListNode* dummy = new ListNode(0,head);
       ListNode* prev = dummy;
       ListNode* curr = head;

        while (curr != NULL) {
            if (st.find(curr->val) != st.end()) {
                // Remove the current node
                prev->next = curr->next;
                curr = curr->next;
            } else {
                // Move to the next node
                prev = curr;
                curr = curr->next;
            }
        }
        // Return the new head (dummy->next)
        return dummy->next;
    }
};