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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k == 0)
            return head;

        // find the length of linked list
        int len = 1 ;
        ListNode* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
            len++;
        }

        // Reduce / resize k
        k = k % len;
        if(k == 0)
            return head;

        // Find new tail at position (len - k - 1) i.e. 1 node before kth node
        ListNode* newTail = head;
        for(int i=0; i<len-k-1; i++){
            newTail = newTail->next;
        }

        //Rewire
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        curr->next = head;
        
        return newHead;
    }
};