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
    ListNode* reverseLL(ListNode* head){

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;

        return last;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;
        int count = 0;
        while(temp != NULL && count < k){
            count++;
            temp = temp->next;
        }

        if(count < k) // less thank k nodes left, return head
            return head;

        ListNode* tail = head;
        for(int i=0; i<k-1; i++){
            tail = tail->next;
        }
        tail->next = NULL; // reverseLL -->only sees K nodes

        ListNode* newHead = reverseLL(head);
        head->next = reverseKGroup(temp, k); // head is tail now

        return newHead;
    }
};