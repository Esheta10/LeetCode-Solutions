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
    int lengthOfLinkedList(ListNode* head){

        int l = 0;
        while(head != NULL){
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int L = lengthOfLinkedList(head);

        if(L==n){

            ListNode* temp  = head->next;
            delete(head);
            return temp;
        }

        int travel_front = L-n;

        ListNode* prev = NULL;
        ListNode* temp = head;

        while(travel_front--){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete(temp);
        return head;
    }
};