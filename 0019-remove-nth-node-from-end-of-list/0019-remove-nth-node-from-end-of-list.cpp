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
    int getLengthOfLinkedList(ListNode* head){

        int count = 0;
        ListNode* curr = head;

        while(curr != NULL){
            count++;
            curr = curr->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int L = getLengthOfLinkedList(head);

        int travel_front = L - n;

        if(n == L){ // delete head node
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(travel_front--){
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;

        delete(temp);

        return head;
    }
};